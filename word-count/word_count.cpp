#include "word_count.h"
#include <vector>

using namespace std;

bool delim(const char &c) {
    return c == ' ' || c == '\n' || c == ',';
}

const map<string, int> word_count::words(const string &text) {
    map<string, int> wordcount {};
    vector<char> wordchars {};
    for ( unsigned int i = 0; i < text.length(); i++ ) {
        auto &c = text[i];
        if ( delim(c) && !wordchars.empty() ) {
            wordcount[string(wordchars.begin(), wordchars.end())] += 1;
            wordchars = vector<char>();
        } 
        else if ( (c == '\'' && isalnum(text[i - 1]) && isalnum(text[i + 1])) 
                  || isalnum(c) ) {
            wordchars.push_back(tolower(c));
        }
        else continue;
    }
    if ( !wordchars.empty()) 
        wordcount[string(wordchars.begin(), wordchars.end())] += 1;
    return wordcount;
}
