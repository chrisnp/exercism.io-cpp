#include "binary.h"
#include <cmath>

using namespace std;

long binary::convert (string binstr) {
    for (auto& d: binstr) {
        if (!isdigit(d)) return 0;
    }
    auto binary {stoll(binstr)}; 
    long decimal {0}, pos {0};
    while (binary != 0) {
        decimal += (binary % 10) * pow(2, pos);
        pos++;
        binary /= 10;
    }
    return decimal;
}
