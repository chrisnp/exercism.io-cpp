#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>
#define EXERCISM_RUN_ALL_TESTS

using namespace boost::posix_time;

namespace gigasecond {

ptime advance(ptime const &);

}