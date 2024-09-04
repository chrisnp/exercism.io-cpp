#pragma once

#include <stdexcept>

namespace circular_buffer {
using std::string;

template <typename T> struct circular_buffer {

    explicit circular_buffer(size_t size)
    : _read_idx {0}, 
      _write_idx {0}, 
      _capacity {size}, 
      _buffer {new T[size]}
    { clear(); };

    [[nodiscard]] auto const read() -> T& {
        if (current_size() == 0) 
            throw std::domain_error("Buffer is empty.");
        size_t curr_read = _read_idx;
        advance(_read_idx);
        return _buffer[curr_read];   
    }
    auto write(const T& item) -> void {
        if (current_size() == capacity())
            throw std::domain_error("Buffer is full.");
        _buffer[_write_idx] = item;
        advance(_write_idx);
        if (_write_idx == _read_idx) advance(_read_idx);
    }
    auto overwrite(const T& item) -> void {
        if (current_size() >= capacity()) advance(_read_idx);
        write(item);
    }
    auto clear() -> void { _write_idx = _read_idx = 0; }

    ~circular_buffer() { delete[] _buffer; };

protected:
    auto capacity() const -> size_t { return _capacity; }
    auto current_size() const -> size_t {
        return _write_idx >= _read_idx 
               ? _write_idx - _read_idx 
               : capacity() - (_read_idx - _write_idx - 1);
    }
    auto empty() const -> bool { return _write_idx == _read_idx; }

private:
    size_t _read_idx, _write_idx;
    size_t _capacity;
    T *_buffer;
    auto advance(size_t& val) -> void { ++val %= _capacity + 1; }
}; // struct circular_buffer

}  // namespace circular_buffer


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif
