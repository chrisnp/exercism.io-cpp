#include "robot_name.h"
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

namespace {

using uchar = unsigned char;
using uint = unsigned int;

constexpr auto max_possible {26 * 26 * 1000};
uint name_idx {0}; 

auto all_names() noexcept -> std::vector<std::string> {
    auto all_names = std::vector<std::string> {};
    all_names.reserve(max_possible);
    // Generate all possible names
    for (uchar letter_a = 'A'; letter_a <= 'Z'; ++letter_a)
        for (uchar letter_b = 'A'; letter_b <= 'Z'; ++ letter_b)
            for (uint digits = 0; digits < 1000; ++digits) {
                char name[6] {};
                std::snprintf(name, sizeof(name), "%c%c%.3u", 
                              letter_a, letter_b, digits);
                all_names.emplace_back(name);
            }
    // and shuffle them
    static auto rnd = std::default_random_engine {};
    std::shuffle(std::begin(all_names), std::end(all_names), rnd);
    return all_names; 
}

} // namespace

namespace robot_name {

robot::robot() { 
    robot::reset(); 
} 

auto robot::name() const noexcept -> std::string const& {
    return robot::_name;
}

void robot::reset() {
    static auto names = all_names();
    if (name_idx == max_possible) 
        throw std::domain_error("Out of names");
    robot::_name = names.at(++name_idx);
}

}  // namespace robot_name
