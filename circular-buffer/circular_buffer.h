#pragma once

#include <memory>
#include <stdexcept>

namespace circular_buffer {

using size_t = std::size_t;

template <typename T>
struct circular_buffer {
    using uptr_t = std::unique_ptr<T>;

    explicit circular_buffer(size_t size) 
    : _head {0}, _last {0}, _size {0}, _capacity {size},    
      _buffer {new uptr_t[size]}  
    { clear(); }

    ~circular_buffer() { delete[] _buffer; }

    auto capacity() const -> size_t { return _capacity; }
    auto size() const -> size_t {
        return _head >= _last 
               ? _head - _last 
               : _capacity - (_last - _head);
    }

    auto const read() -> T {
        if (size() == 0) {
            throw std::domain_error("Empty. Nothing to read");
        }
        auto item = *_buffer[_head];
        advance(_head);
        _size--;
        return item;
    };

    auto write(const T& item) -> void {
        if (size() == capacity() && _head == _last) {
            throw std::domain_error("Full. Can't write");
        }
        _buffer[_last] = std::make_unique<T>(item);
        advance(_last);
        _size++;
    };
    auto overwrite(const T& item) -> void {
        if (size() >= capacity()) {
            advance(_last);
            // ++_size;
        }
        write(item);
    };
    auto clear() -> void { _head = _last = 0L; }
    
private:
    size_t _head, _last;
    size_t _size, _capacity;
    uptr_t* _buffer;
    auto advance(size_t& val) -> void {
        ++val %= _capacity;
    }
};

}  // namespace circular_buffer


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif