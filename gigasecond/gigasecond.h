#pragma once
#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond {

    using ptime = boost::posix_time::ptime;
    using seconds = boost::posix_time::seconds;
    using time_duration = boost::posix_time::time_duration;

    static const auto GIGASEC { (long) 1E9 };
    static const time_duration GIGASECOND { seconds(GIGASEC) }; 

    inline ptime advance(ptime const &time_now) {
        return time_now + GIGASECOND;
    }
}


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif