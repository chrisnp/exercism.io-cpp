#pragma once
#include <vector>

namespace pascals_triangle {

constexpr auto factorial (const int n) noexcept -> int { 
    return n == 0 ? 1 : n * factorial(n - 1);
}
constexpr auto binomial (int n, int k) noexcept -> int {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
using ptriangle_t = std::vector<std::vector<int>>;
const ptriangle_t generate_rows(int);
} // namespace pascals_triangle 


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif