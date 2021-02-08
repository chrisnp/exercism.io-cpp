#pragma once

#include <cstdint>

namespace space_age {

class space_age {

    uint_fast64_t age;

public:
    space_age(uint_fast64_t);
    uint_fast64_t seconds() const;
    float on_mercury() const;
    float on_venus() const;
    float on_earth() const;
    float on_mars() const;
    float on_jupiter() const;
    float on_saturn() const;
    float on_uranus() const;
    float on_neptune() const;
};
}

#define EXERCISM_RUN_ALL_TESTS