#include "bob.h"

using namespace std;

string bob::hey(const string &query) {
    if (regex_search(query, bob::shout) && 
        regex_search(query, bob::question)) {
        return bob::RESPONSE_EMPHATIC;
    }
    if (regex_search(query, bob::shout)) {
        return bob::RESPONSE_SHOUTING;
    }
    if (regex_search(query, bob::question)) { 
        return bob::RESPONSE_QUESTION; 
    }
    if (regex_search(query, bob::silence)) { 
        return bob::RESPONSE_SILENCE; 
    }
    return bob::RESPONSE_DEFAULT;
}
