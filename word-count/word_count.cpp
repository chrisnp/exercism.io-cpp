#include "word_count.h"
#include <vector>

using namespace std;

constexpr auto delim( const char &c ) -> bool {
    return c == ' ' || c == ',' || c == '\n';
}

const map<string, int> word_count::words( const string &text ) {
    map<string, int> wordcount {};
    vector<char> wordchars {};
    for ( unsigned int i = 0; i < text.length(); i++ ) {
        auto &c = text[i];
        if ( delim(c) && !wordchars.empty() ) {
            ++wordcount[string(wordchars.begin(), wordchars.end())];
            wordchars = vector<char>();
        } 
        else if ( (c == '\'' && isalnum(text[i - 1]) && isalnum(text[i + 1])) 
                  || isalnum(c) ) {
            wordchars.push_back(tolower(c));
        }
        else continue;
    }
    if ( !wordchars.empty() ) 
        ++wordcount[string(wordchars.begin(), wordchars.end())]++;
    return wordcount;
}
