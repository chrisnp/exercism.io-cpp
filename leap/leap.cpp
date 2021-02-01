#include "leap.h"

bool divBy400(int year) {
    return (year % 400 == 0);
}

bool divBy100(int year) {
    return (year % 100 == 0);
}

bool divBy004(int year) {
    return (year % 4 == 0);
}

bool leap::is_leap_year(int year) {
    if (divBy100(year)) {
        return divBy400(year);
    }
    return divBy004(year);
}