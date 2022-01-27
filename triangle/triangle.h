#pragma once

namespace triangle {
    
    enum class flavor {
        equilateral, 
        isosceles,
        scalene
    };

    flavor kind(double, double, double);

}  // namespace triangle

namespace doubles {

    constexpr double maximum(double a, double b, double c) {
        return (a >= b) ? (a >= c ? a : c) : (b >= c ? b : c);
    }

    constexpr double minimum(double a, double b, double c) {
        return (a <= b) ? (a <= c ? a : c) : (b <= c ? b : c);
    }

} // namespace doubles

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif