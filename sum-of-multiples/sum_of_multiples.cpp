#include "sum_of_multiples.h"
#include <numeric>

using namespace std;

bool multiple(long candidate, sum_of_multiples::divisors factors) {
    for (auto x : factors)
        if (x != 0 && !(candidate % x)) 
            return true;
        else continue;
    return false;
}

long sum_of_multiples::to(sum_of_multiples::divisors factors, long up_to) {
    vector<long> multiples {0};
    for (long i {0}; i < up_to; ++i) if (multiple(i, factors))
            multiples.push_back(i);
    return accumulate(multiples.begin(), multiples.end(), 0);
}
