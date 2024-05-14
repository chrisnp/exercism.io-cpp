#include "run_length_encoding.h"

using std::string;
using std::to_string;

string run_length_encoding::encode(const string &plaintext) noexcept {
    auto encoded = string {};
    if (plaintext.empty()) return encoded;
    auto count = int {0};
    auto curr = char {plaintext.at(0)};
    for (auto ch : plaintext) {
        if (ch == curr) count++;
        else {
            if (count > 1) encoded += to_string(count);
            encoded.push_back(curr);
            curr = ch;
            count = 1;
        }
    }
    if (count > 1) encoded += to_string(count);
    encoded.push_back(curr);
    return encoded;
}

string run_length_encoding::decode(const string &encoded) noexcept {
    auto decoded = string {};
    auto run = int {0};
    for (auto ch : encoded) {
        if (isdigit(ch)) run = 10 * run + ch - '0';
        else {
            if (run == 0) run = 1;
            for (auto i = int{0}; i < run; ++i) decoded += ch;
            run = 0;
        }
    } 
    return decoded;
}
