#include "allergies.h"

using namespace std;

allergies::allergy_test::allergy_test(unsigned short score) {
    score &= 0xff;
    for (int i = 0; i < static_cast<int>(ALLERGENS.size()); i++) 
        if (1 << i & score) allergies.insert(ALLERGENS.at(i));
}

bool allergies::allergy_test::is_allergic_to(const string &allergen) {
    return allergies.count(allergen) != 0;
}

unordered_set<string> allergies::allergy_test::get_allergies() const {
    return allergies::allergy_test::allergies;
}
