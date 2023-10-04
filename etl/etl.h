#pragma once
#include <map>
#include <vector>

constexpr auto _tolower(const char &__c) noexcept -> unsigned char { 
    return __c - 'A' + 'a'; 
} 

namespace etl {
    using legacy_data = std::map<int, std::vector<char>>;
    using shiny_new_system = std::map<char, int> ;
    inline shiny_new_system transform(legacy_data const &legacy_scores) {
        shiny_new_system new_system {};
        for (auto legacy_score : legacy_scores) 
            for (auto letter : legacy_score.second) 
                new_system[_tolower(letter)] = legacy_score.first;
        return new_system;
    }
}  // namespace etl

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif