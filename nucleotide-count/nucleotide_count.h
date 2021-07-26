#pragma once

#include <string>
#include <map>


namespace nucleotide_count {

typedef std::map<char, int> nucl_counts;

class counter {
    nucl_counts counts = {
        {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}
    };

public: 
    counter(std::string strand);
    const nucl_counts nucleotide_counts() const {
        return counts;
    };
    int count(char) const;

private:
    nucl_counts count(std::string) const;
};
}  // namespace nucleotide_count

#define EXERCISM_RUN_ALL_TESTS