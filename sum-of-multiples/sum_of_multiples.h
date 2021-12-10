#pragma once

#include <vector>

namespace sum_of_multiples {

typedef std::vector<long> divisors;

long to(divisors factors, long up_to);

}  // namespace sum_of_multiples

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif