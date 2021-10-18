#pragma once

#include <map>
#include <vector>

namespace etl {
    typedef std::map<int, std::vector<char>> legacy_data;
    typedef std::map<char, int> shiny_new_system;
    shiny_new_system transform(legacy_data const &);

}  // namespace etl

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif