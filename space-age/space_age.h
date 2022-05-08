#pragma once

#include <cstdint>

namespace space_age {

class space_age {

    uint_fast64_t age;

public:
    explicit space_age(const uint_fast64_t);
    uint_fast64_t seconds() const;
    float on_mercury() const noexcept;
    float on_venus() const noexcept;
    float on_earth() const noexcept;
    float on_mars() const noexcept;
    float on_jupiter() const noexcept;
    float on_saturn() const noexcept;
    float on_uranus() const noexcept;
    float on_neptune() const noexcept;

};
} // namespace space_age

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif