#include "all_your_base.h"

#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

vector<unsigned int> all_your_base::convert(unsigned int in_base, 
                                            const vector<unsigned int> &in_representation, 
                                            unsigned int out_base) {
    vector<unsigned int> out_representation;
    if (in_base < 2 || out_base < 2) 
        throw invalid_argument("bases must be at least 2");
    if (in_representation.size() == 0)
        return out_representation;
    int sum {0}; int pos {0};
    for (auto digit = in_representation.rbegin(); digit != in_representation.rend(); ++digit) {
        if (*digit >= in_base) 
            throw invalid_argument("invalid digit");
        sum += *digit * pow(in_base, pos);
        ++pos;
    }
    while (sum >= 1) {
        out_representation.push_back(sum % out_base);
        sum /= out_base;
    } 
    reverse(out_representation.begin(), out_representation.end());
    return out_representation;
}