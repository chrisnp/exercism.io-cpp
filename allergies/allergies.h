#pragma once

#include <vector>
#include <unordered_set>

namespace allergies {

class allergy_test {

public:
    explicit allergy_test(unsigned short);
    bool is_allergic_to(const std::string &);
    std::unordered_set<std::string> get_allergies() const;
private:
    std::unordered_set<std::string> allergies;
    std::vector<std::string> ALLERGENS = {
        "eggs", "peanuts", "shellfish", "strawberries",
        "tomatoes", "chocolate", "pollen", "cats"
    };
};

}  // namespace allergies

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif