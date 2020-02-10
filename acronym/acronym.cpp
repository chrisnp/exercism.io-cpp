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
        char * it { 
            find(_bounds, _bounds + 3, ch) 
        };
        if (it != _bounds + 3) 
            boundary = true;
    }
    return acro;
}
