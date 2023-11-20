#pragma once

#include <vector>

namespace triangle {
    
enum class flavor {
    equilateral, 
    isosceles,
    scalene
};

auto kind(double, double, double) -> flavor;

}  // namespace triangle

namespace doubles {

[[nodiscard, gnu::pure]] 
auto maximum(std::vector<double>&) noexcept -> double;

[[nodiscard, gnu::pure]]    
auto minimum(std::vector<double>&) noexcept -> double;

[[nodiscard, gnu::pure]]    
auto kahanSum(std::vector<double>&) noexcept -> double; 

} // namespace doubles

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif