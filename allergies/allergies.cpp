#include "allergies.h"

allergies::allergy_test::allergy_test(unsigned short score) {
    score &= 0xff;
    for (int i = 0; i < static_cast<int>(ALLERGENS.size()); i++) 
        if (1 << i & score) allergies.insert(ALLERGENS.at(i));
}

bool allergies::allergy_test::is_allergic_to(const std::string &allergen) {
    return allergies.count(allergen) != 0;
}

std::unordered_set<std::string> allergies::allergy_test::get_allergies() const {
    return allergies::allergy_test::allergies;
}
