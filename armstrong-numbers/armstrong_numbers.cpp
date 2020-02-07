#include "armstrong_numbers.h"

using namespace std;

bool armstrong_numbers::is_armstrong_number(const int & num) {

    const string digits { to_string(num) };

    int num_digits { (int) digits.length() }, 
        sum_digits_raised {};

    for (auto digit : digits) {
        sum_digits_raised += pow(digit - '0', num_digits); 
    }

    return num >= 0 && sum_digits_raised == num;
}