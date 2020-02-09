#include "reverse_string.h"

using namespace std;

string reverse_string::reverse_string(const string &_str) {
    
    return string(_str.rbegin(), _str.rend());
    
}
