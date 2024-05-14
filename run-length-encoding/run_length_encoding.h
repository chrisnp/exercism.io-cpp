#pragma once

#include <string>

namespace run_length_encoding {

using std::string;

[[nodiscard]] auto encode(const string&) noexcept -> string;
[[nodiscard]] auto decode(const string&) noexcept -> string;

}  // namespace run_length_encoding
