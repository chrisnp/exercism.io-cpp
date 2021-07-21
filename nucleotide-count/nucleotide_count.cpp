#include "nucleotide_count.h"
// #include <stdexcept>

nucleotide_count::counter::counter(std::string strand) {
    for (auto &s : strand) {
        switch(s) {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                counts[s]++;
                break;
            default: 
                throw std::invalid_argument("invalid nucleotide");
        }
    }
}

int nucleotide_count::counter::count(char n) const {
    try {
        return counts.at(n);
    } catch(const std::logic_error&) {
        throw std::invalid_argument("invalid nucleotide");
    }
}
