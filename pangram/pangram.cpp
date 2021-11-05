#include "pangram.h"
#include <bitset>

using namespace std;
using alphabet = bitset<pangram::ALPHABET_SIZE>;

constexpr int letter_idx(char ch) noexcept {
    return tolower(ch) - 'a';
}

bool pangram::is_pangram(const string &sentence) noexcept {
    if (sentence.size() < pangram::ALPHABET_SIZE) return false;
    alphabet letters;
    for (const char ch: sentence) if (isalpha(ch)) {
        letters.set(letter_idx(ch));
    }
    return letters.all();
}
