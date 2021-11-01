#include "pangram.h"
#include <bitset>

using namespace std;
using alphabet = bitset<26>;

static constexpr unsigned letter_idx(char ch){
    return tolower(ch) - 'a';
}

bool pangram::is_pangram(const string &sentence) {
    alphabet every_letter;

    for (char ch: sentence) {
        if (!isalpha(ch)) continue;
        every_letter.set(letter_idx(ch));
    }
    
    if (every_letter.all()) return true;
    return false;
}
