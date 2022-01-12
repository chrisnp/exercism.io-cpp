#include "trinary.h"
#include <algorithm>

bool valid(std::string const &trinary) {
    return std::all_of(trinary.begin(), trinary.end(), [](char d) {
        return ('0' <= d) && (d <= '2');
    });
}

int trinary::to_decimal(const std::string &trinary) noexcept {
    if (!valid(trinary)) return 0;
    int decimal, dval {0};
    for (auto d = trinary.begin(); d < trinary.end(); ++d) {
        decimal += decimal << 1;
        dval = *d - '0';
        if (dval > 2) continue;
        decimal += dval;
    }
    return decimal;
}