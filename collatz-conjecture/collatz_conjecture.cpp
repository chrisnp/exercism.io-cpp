#include "collatz_conjecture.h"

using namespace std;

unsigned int collatz_conjecture::steps (const int &_num) {

    int num { _num },
        steps { 0 };

    if (num <= 0) 
        throw domain_error("not a positive integer");

    while (num != 1) {
        ++steps;
        if (num & 1) {
            num *= 3, 
            num += 1;
        }
        else 
            num >>= 1;
    }

    return steps;
} 
