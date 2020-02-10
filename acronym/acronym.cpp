#include "acronym.h"

using namespace std;

const string acronym::acronym(const string &_phrase) {

    string acro { "" },
           phrase { _phrase };

    bool boundary { true };

    // word boundaries
    char _bounds[] = {' ', '_', '-'};
    
    for (auto ch : phrase) {
        if (isalnum(ch) && boundary) {
            acro += toupper(ch);
            boundary = false;
        } 
        // check if ch is in word boundaries
        char * it { 
            find(begin(_bounds), end(_bounds), ch) 
        };
        // if it is, switch boundary 
        if (it != end(_bounds)) 
            boundary = true;
    }
    return acro;
}
