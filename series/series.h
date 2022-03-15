#pragma once

#include <string>
#include <vector>

namespace series {

std::vector<int> digits(std::string const &);
std::vector<std::vector<int>> slice(std::string const &, size_t);

}  // namespace series

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif