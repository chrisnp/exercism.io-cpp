#pragma once

#include <string>
#include <vector>

namespace anagram {
    using std::string;
    using std::vector;

class anagram {
public:
    anagram(string const);
    vector<string> matches(vector<string> const &);
private:
    string subject;
    string normal;
};
}  // namespace anagram

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif