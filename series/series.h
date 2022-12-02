#pragma once

#include <string>
#include <vector>

namespace series {

std::vector<std::string> slice(std::string const &, uint32_t);

}  // namespace series

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif