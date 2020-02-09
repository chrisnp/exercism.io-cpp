#include "reverse_string.h"

using namespace std;

string reverse_string::reverse_string(const string &_str) {

    long unsigned int len { _str.length() };
    string str { _str };
    
    return len == 0 ? 
           str      : 
           reverse_string::reverse_string(str.substr(1, len - 1)) 
                           + str.at(0);
}
