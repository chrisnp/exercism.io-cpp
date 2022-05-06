#include "atbash_cipher.h"

using namespace std;

string atbash_cipher::encode(const string &plain) {
    string cipher {};
    for( char c: plain) {
        bool digit  = '0' <= c && c <= '9';
        bool letter = 'a' <= c && c <= 'z';
        
    }
}

string atbash_cipher::decode(const string &cipher) {

}
