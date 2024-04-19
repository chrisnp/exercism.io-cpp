#include "word_count.h"
#include <vector>

const word_count::words_map_t word_count::words( const std::string &text ) {
    constexpr auto word_delimiter = [&]( const char &c ) noexcept -> bool {
        return c == ' ' || c == ',' || c == '\n';
    };
    word_count::words_map_t wordcount {};
    std::vector<char> wordchars {};
    for ( unsigned int i = 0; i < text.length(); i++ ) {
        const auto &c = static_cast<char>(text[i]);
        if ( isalnum(c) ) {
            wordchars.push_back(std::tolower(c));
        }
        else if ( c == '\'' && !wordchars.empty() && isalnum(text[i + 1]) ) {
            wordchars.push_back(std::tolower(c));
        }
        else if ( word_delimiter(c) && !wordchars.empty() ) {
            wordcount[std::string(wordchars.begin(), wordchars.end())] += 1;
            wordchars = std::vector<char>();
        }  
        else continue;
    }
    if ( !wordchars.empty() ) 
        wordcount[std::string(wordchars.begin(), wordchars.end())] += 1;
    return wordcount;
}
