#include "nth_prime.h"
#include <vector>

using namespace std;

unsigned long nth_prime::nth(unsigned long num) {

    if (num == 0) {
        throw std::domain_error("No zeroth prime");
    }

    vector<unsigned long> primes {2};
    unsigned long candidate {3};

    while (primes.size() < num) {
        bool is_prime = true;
        for (auto p: primes) {
            if (candidate % p == 0) {
                candidate += 2;
                is_prime = false;
                break;
            } 
        }
        if (is_prime) {
            primes.push_back(candidate);
            candidate += 2;
        }
    }
    return primes[num - 1];
}
