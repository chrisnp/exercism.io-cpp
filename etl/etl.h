#pragma once

#include <map>
#include <vector>

namespace etl {
    typedef std::map<int, std::vector<char>> legacy_data;
    typedef std::map<char, int> shiny_new_system;
    inline shiny_new_system transform(legacy_data const &legacy_scores) {
        shiny_new_system new_system {};
        for (auto legacy_score : legacy_scores) 
            for (auto letter : legacy_score.second) 
                new_system[std::tolower(letter)] = legacy_score.first;
        return new_system;
    }
}  // namespace etl

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif