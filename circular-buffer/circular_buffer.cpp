#include "circular_buffer.h"

namespace circular_buffer {

template <typename T>
circular_buffer<T>::circular_buffer(size_t size)
: _ridx {0}, _widx {0}, _capacity {size}, _buffer {new T[size]}
{ clear(); }

template <typename T>
circular_buffer<T>::~circular_buffer() { delete[] _buffer; }

template <typename T> 
auto const circular_buffer<T>::read() -> T& {
    if (current_size() == 0) {
        throw std::domain_error("Buffer is empty.");
    }
    size_t curr_ridx = _ridx;
    advance(_ridx);
    return _buffer[curr_ridx];
}
template <typename T> void circular_buffer<T>::write(const T& item) {
    if (current_size() == capacity()) {
        throw std::domain_error("Buffer is full.");
    }
    _buffer[_widx] = item;
    advance(_widx);
    if (_widx == _ridx) advance(_ridx);
}
template <typename T> void circular_buffer<T>::overwrite(const T& item) {
    if (current_size() >= capacity()) {
        advance(_ridx);
    }
    write(item);
}
template <typename T> void circular_buffer<T>::clear() { 
    _widx = _ridx = 0L;
}
template <typename T> size_t circular_buffer<T>::capacity() const {
    return _capacity;
}
template <typename T> size_t circular_buffer<T>::current_size() const {
    return _widx >= _ridx ? _widx - _ridx 
           : circular_buffer<T>::capacity() + 1U - (_ridx - _widx);
}
template <typename T> void circular_buffer<T>::advance(size_t& val) {
        ++val %= _capacity + 1;
}
}  // namespace circular_buffer
