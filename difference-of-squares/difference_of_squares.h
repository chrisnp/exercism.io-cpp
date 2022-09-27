#pragma once

#include <cmath>

namespace difference_of_squares {

constexpr int ipow(int base, int exp) {
    return 
        exp == 1 
        ? base
        : ipow(base, (exp >> 1) + 
          (exp & 1)) * ipow(base, exp >> 1);
}

long int square_of_sum(const int&);
long int sum_of_squares(const int&);
long int difference(const int&);

}
