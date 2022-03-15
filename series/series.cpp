#include "series.h"
#include <stdexcept>

using namespace std;

vector<int> series::digits(string const &input) {
    vector<int> digits {};
    for (auto &c: input) {
        int d = c - '0';
        if (d < 0 || d > 9) 
            throw domain_error("invalid digit");
        digits.push_back(d);
    }
    return digits;
}

vector<vector<int>> series::slice(string const &input, size_t size) {
    vector<int> digits = series::digits(input);
    size_t input_size = digits.size();
    if (input_size < size)
        throw domain_error("cannot slice shorter string");
    vector<vector<int>> slices {};
    for (size_t i = 0; i <= input.size() - size; ++i) {
        slices.push_back(series::digits(input.substr(i, size)));
    }  
    return slices;
}