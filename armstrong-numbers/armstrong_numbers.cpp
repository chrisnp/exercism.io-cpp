#include "armstrong_numbers.h"
#include <cmath>
#include <string>

bool armstrong_numbers::is_armstrong_number(const int &num) noexcept {
    const std::string digits { std::to_string(num) };

    int num_digits { (int) digits.length() }, 
        sum_digits_raised { 0 };

    for (auto digit : digits) {
        sum_digits_raised += pow(digit - '0', num_digits); 
    }

    return num >= 0 && sum_digits_raised == num;
}