#pragma once

#include <stdexcept>

namespace circular_buffer {
using std::string;

template <typename T> struct circular_buffer {

    explicit circular_buffer(size_t size)
    : _read_idx {0}, 
      _write_idx {0}, 
      _capacity {size}, 
      _size {0},
      _buffer {new T[size]}
    { };

    [[nodiscard]] 
    auto const read() -> T {
        if (current_size() == 0) 
            throw std::domain_error("Buffer is empty.");
        T curr_read = _buffer[_read_idx];
        advance(_read_idx);
        --_size;
        return curr_read;   
    }  

    auto write(const T& item) -> void {
        if (current_size() == capacity())
            throw std::domain_error("Buffer is full."); 
        _buffer[_write_idx] = item;
        advance(_write_idx);
        ++_size;
    }

    auto overwrite(const T& item) -> void {
        if (current_size() == capacity()) {
            // If buffer is full, overwrite oldest
            _buffer[_write_idx] = item;
            advance(_write_idx);
            advance(_read_idx);
        } else {
            // otherwise..
            write(item);
        }
    }

    auto clear() -> void { _write_idx = _read_idx = _size = 0; }

    ~circular_buffer() { delete[] _buffer; };

protected:
    auto capacity() const -> size_t { return _capacity; }
    auto current_size() const -> size_t { return _size; }
    auto advance(size_t& val) -> void { ++val %= _capacity; }
    auto empty() const -> bool { return _write_idx == _read_idx; }

private:
    size_t _read_idx, _write_idx, _capacity, _size;
    T *_buffer;
}; // struct circular_buffer

}  // namespace circular_buffer


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif
