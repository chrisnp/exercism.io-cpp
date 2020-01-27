#include "leap.h"

namespace leap {

    bool divBy400(int year) {
        return (year % 400 == 0);
    }

    bool divBy100(int year) {
        return (year % 100 == 0);
    }

    bool divBy004(int year) {
        return (year % 4 == 0);
    }

    bool is_leap_year(int year) {
        return divBy004(year) && 
              (divBy400(year) || !divBy100(year));
    }
}  // namespace leap
