#include "gigasecond.h"

static const int GIGASEC {(long) 1E9f};

static const time_duration GIGASECOND { seconds(GIGASEC) };

ptime gigasecond::advance(ptime const &time_now) {
    return time_now + GIGASECOND;
}
