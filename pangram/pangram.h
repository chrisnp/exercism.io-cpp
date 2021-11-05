#pragma once

#include <string>

namespace pangram {

constexpr int ALPHABET_SIZE { 26 };

bool is_pangram(const std::string &) noexcept;

}  // namespace pangram

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif
