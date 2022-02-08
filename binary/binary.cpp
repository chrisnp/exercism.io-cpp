#include "binary.h"
#include <cmath>

using namespace std;

int binary::convert (string binstr) {

    for (auto& d: binstr) {
        if (!isdigit(d)) 
            return 0;
    }
        
    auto binary = std::stol(binstr); 
    int decimal = 0, pos = 0;

    while (binary != 0) {
        decimal += (binary % 10) * pow(2, pos);
        pos++;
        binary /= 10;
    }
    return decimal;
}
