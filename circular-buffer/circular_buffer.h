#pragma once

#include <stdexcept>

namespace circular_buffer {

using size_t = std::size_t;
using std::string;

template <typename T> struct circular_buffer {

    explicit circular_buffer(size_t);
    ~circular_buffer();
    [[nodiscard]] auto const read() -> T&;
    auto write(const T& item) -> void;
    auto overwrite(const T& item) -> void;
    auto clear() -> void;

protected:
    auto capacity() const -> size_t;
    auto current_size() const -> size_t;
    // auto empty() const -> bool { return _widx == _ridx; }
    
private:
    size_t _ridx, _widx;
    size_t _capacity;
    T *_buffer;
    auto advance(size_t& val) -> void;
};

/**
    And two needed declarations, to keep the linker happy.
*/
template struct circular_buffer<int>;
template struct circular_buffer<std::string>;

}  // namespace circular_buffer


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif