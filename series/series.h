#pragma once

#include <string>
#include <vector>

namespace series {

using uint_t = unsigned int;

std::vector<std::string> slice(std::string const &, uint_t);

}  // namespace series

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif