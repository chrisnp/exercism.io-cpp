#pragma once
#include <string>
#include <map>

namespace nucleotide_count {

typedef std::map<char, int> ncounts_t;

auto count(std::string) -> ncounts_t;

}  // namespace nucleotide_count

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif