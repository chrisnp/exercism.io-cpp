#include "binary.h"

using namespace std;

int binary::convert (string binstr) {

    for (auto& d: binstr) {
        if (!isdigit(d)) 
            return 0;
    }

    auto binary = stol(binstr); 
    unsigned int decimal {0}, 
                 pos {0};
                 
    while (binary != 0) {
        decimal += 
            (binary % 10) * pow(2, pos);
        pos++;
        binary /= 10;
    }
    return decimal;
}