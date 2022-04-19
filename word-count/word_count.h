#pragma once
#include <map>
#include <string>

namespace word_count {

const std::map<std::string, int> words(const std::string&);

}  // namespace word_count

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif