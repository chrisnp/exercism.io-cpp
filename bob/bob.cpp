#include "bob.h"
#include <regex>

using namespace std;

const regex shout {"^[[:lower:]]+[[:upper:]][^[:lower:]]+$"};
const regex question {"\\?$"};
const regex silence {"^\\W*$"};

string bob::hey(const string &query) {
    if (regex_search(query, shout)) {
        if (regex_search(query, question)) {
            return bob::RESPONSE_EMPHATIC;
        } 
        else {
            return bob::RESPONSE_SHOUT;
        }
    }
    if (regex_search(query, question)) { 
        return bob::RESPONSE_QUESTION; 
    }
    if (regex_search(query, silence)) { 
        return bob::RESPONSE_SILENCE; 
    }
    return bob::RESPONSE_DEFAULT;
}
