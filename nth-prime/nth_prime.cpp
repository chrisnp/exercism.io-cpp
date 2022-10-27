#include "nth_prime.h"

unsigned long nth_prime::nth(unsigned long num) {
    using namespace std;

    if (num == 0) {
        throw domain_error("No zeroth prime");
    }

    vector<unsigned long> primes {{2}};
    unsigned long candidate {3};

    while (primes.size() < num) {
        bool is_prime = true;
        for (auto p: primes) {
            if (candidate % p == 0) {
                is_prime = false;
                continue;
            } 
        }
        if (is_prime) primes.push_back(candidate);
        candidate += 2;
    }
    return primes[num - 1];
}
