#pragma once

#include <string>
#include <vector>

namespace anagram {

class anagram {

public:
    anagram(std::string const);
    std::vector<std::string> matches(std::vector<std::string> const &);

private:
    std::string subject;
    std::string normal;

};
}  // namespace anagram

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif