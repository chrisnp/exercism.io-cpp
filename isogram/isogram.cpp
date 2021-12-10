#include "isogram.h"
#include <set>

bool isogram::is_isogram(const string &word) {

    set<char> isogram {};
    
    for(char ch : word) {

        if (!isalpha(ch)) continue;
        
        ch = tolower(ch);

        if (isogram.count(ch) > 0) 
            return false;
        
        isogram.insert(ch);
    }
    return true;
}
