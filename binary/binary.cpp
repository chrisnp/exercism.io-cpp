#include "binary.h"

namespace binary {

    int convert (std::string binstr) {

        for (auto& d: binstr) {
            if (!std::isdigit(d)) 
                return 0;
        }

        auto binary = std::stol(binstr); 
        int decimal = 0, pos = 0;

        while (binary != 0) {
            decimal += 
                (binary % 10) * std::pow(2, pos);
            pos++;
            binary /= 10;
        }
        return decimal;
    }
}