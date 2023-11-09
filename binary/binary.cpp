#include "binary.h"
#include <cmath>

using string = std::string;

long binary::convert (string binstr) noexcept {
    for (auto& d: binstr) if (!isdigit(d)) return 0;
    auto binary {stoll(binstr)}; 
    long decimal { 0 }, position { 0 };
    while (binary != 0) {
        decimal += (binary % 10) * pow(2, position);
        position++;
        binary /= 10;
    }
    return decimal;
}
