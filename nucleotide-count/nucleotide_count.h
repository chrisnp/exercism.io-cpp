#pragma once
#include <string>
#include <map>

namespace nucleotide_count {

typedef std::map<char, int> ncounts;

ncounts count(std::string);

}  // namespace nucleotide_count

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif