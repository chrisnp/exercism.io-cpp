#include "atbash_cipher.h"
#include "test/catch.hpp"

using namespace std;

constexpr auto alpha (const char &c) -> bool {
    return  'a' <= c && c <= 'z';
}

constexpr auto digit (const char &c) -> bool {
    return  '0' <= c && c <= '9';
}

string atbash_cipher::encode(const string &plain) {
    string ciphertext {};
    int index {0};
    for( auto &ch: plain) {
        char c = tolower(ch);
        if( !(alpha(c) || digit(c)) ) continue; 
        if( index > 0 && index % 5 == 0) ciphertext.push_back(' ');
        if( digit(c) ) ciphertext.push_back(c);
        if( alpha(c) ) ciphertext.push_back('z' - c + 'a');        
        ++index;
    }
    return ciphertext;
}

string atbash_cipher::decode(const string &cipher) {
    string plaintext {};
    for( auto &c: cipher ) {
        if( c == ' ') continue;
        if( digit(c) ) plaintext.push_back(c);
        if( alpha(c) ) plaintext.push_back('a' - c + 'z');
        if( !alpha(c) && !digit(c) ) 
            Catch::throw_domain_error("Bad cipher");
    }
    return plaintext;
}
