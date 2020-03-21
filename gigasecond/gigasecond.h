#pragma once

#include <cstdlib>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

namespace gigasecond {

ptime advance(ptime const &);

}  