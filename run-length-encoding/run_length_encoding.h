#pragma once

#include <string>

namespace run_length_encoding {

[[gnu::pure]] auto encode(const std::string&) noexcept -> std::string;
[[gnu::pure]] auto decode(const std::string&) noexcept -> std::string;

}  // namespace run_length_encoding


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif