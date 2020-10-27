#include "secret_handshake.h"
#include <algorithm>

using namespace std;

constexpr unsigned int wink         = 1U << 0;
constexpr unsigned int double_blink = 1U << 1;
constexpr unsigned int close_eyes   = 1U << 2;
constexpr unsigned int jump         = 1U << 3;
constexpr unsigned int mask_16      = 1U << 4;
 
vector<string> secret_handshake::commands(unsigned int code) {
    
    auto handshake = vector<string>{};

    if (code & wink) 
        handshake.push_back("wink");
    if (code & double_blink) 
        handshake.push_back("double blink");
    if (code & close_eyes) 
        handshake.push_back("close your eyes");
    if (code & jump) 
        handshake.push_back("jump");
    if (code & mask_16) 
        reverse(handshake.begin(), handshake.end());

    return handshake;
}
