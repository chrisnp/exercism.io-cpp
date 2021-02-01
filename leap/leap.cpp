#include "leap.h"

bool divBy400(int year) {
    return year % 400 == 0;
}

bool divBy100(int year) {
    return year % 100 == 0;
}

bool divBy004(int year) {
    return year % 4 == 0;
}

bool leap::is_leap_year(int year) {
    bool is_leap = 
        divBy100(year) ? 
        divBy400(year) : 
        divBy004(year) ;
    return is_leap;
}
