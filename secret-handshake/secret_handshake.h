#pragma once

#include <vector>
#include <string>


namespace secret_handshake {

using namespace std;

constexpr unsigned int wink         = 1U << 0;
constexpr unsigned int double_blink = 1U << 1;
constexpr unsigned int close_eyes   = 1U << 2;
constexpr unsigned int jump         = 1U << 3;
constexpr unsigned int mask_16      = 1U << 4;

vector<string> commands(unsigned int code);

}  // namespace secret_handshake

#define EXERCISM_RUN_ALL_TESTS
