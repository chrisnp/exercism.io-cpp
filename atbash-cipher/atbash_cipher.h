#pragma once

#include <string>

namespace atbash_cipher {

std::string encode(const std::string&);
std::string decode(const std::string&);

}  // namespace atbash_cipher

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif