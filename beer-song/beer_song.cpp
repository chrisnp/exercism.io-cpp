#include "beer_song.h"
#include <sstream>

using namespace std;

string beer_song::verse(int n) {
    switch (n) {
        case 0:
            return  "No more bottles of beer on the wall, " 
                    "no more bottles of beer.\nGo "
                    "to the store and buy some more, "
                    "99 bottles of beer on the wall.\n";
        case 1:
            return  "1 bottle of beer on the wall, "
                    "1 bottle of beer.\nTake it down and "
                    "pass it around, no more bottles "
                    "of beer on the wall.\n";
        case 2: 
            return  "2 bottles of beer on the wall, "
                    "2 bottles of beer.\nTake one down "
                    "and pass it around, 1 bottle "
                    "of beer on the wall.\n";
        default:
            ostringstream verses;
            verses  << n     << " bottles of beer on the wall, " 
                    << n     << " bottles of beer.\n"
                                "Take one down and pass it around, "
                    << n - 1 << " bottles of beer on the wall.\n";
        return verses.str();
    }
}

string beer_song::sing(int start, int end) {
    ostringstream verses;
    for( int n = start; n >= end; --n ) {
        if( n != start ) verses << '\n';
        verses << verse(n);
    }
    return verses.str();
}

string beer_song::sing(int start) {
    return sing(start, 0);
}