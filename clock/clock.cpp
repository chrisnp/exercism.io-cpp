#include "clock.h"
// #include <format>
#include <sstream>
#include <iomanip>

#define MINUTES_DAY 1440
#define MINUTES_HOUR 60

date_independent::clock::clock(int ms): minutes {
    (ms % MINUTES_DAY + MINUTES_DAY) % MINUTES_DAY
} {}

date_independent::clock date_independent::clock::at(int hours, int minutes) {
    return clock(hours * MINUTES_HOUR + minutes);
}

date_independent::clock date_independent::clock::plus(int ms) const noexcept {
    return clock(minutes + ms);
}

date_independent::clock date_independent::clock::minus(int ms) const noexcept {
    return clock(minutes - ms);
}

bool date_independent::clock::operator==(const clock &other) const noexcept {
    return minutes == other.minutes;
}

bool date_independent::clock::operator!=(const clock &other) const noexcept {
    return !(*this == other);
}

date_independent::clock::operator std::string() const {
    // return std::format("%02d:%02d", minutes / MINUTES_HOUR, minutes % MINUTES_HOUR);
    std::ostringstream fmt;
    fmt << std::setw(2) << std::setfill('0') << minutes / MINUTES_HOUR 
        << ':' 
        << std::setw(2) << std::setfill('0') << minutes % MINUTES_HOUR;
    return fmt.str();
}