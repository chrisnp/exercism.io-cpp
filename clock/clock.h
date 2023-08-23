#pragma once
#include <string>

namespace date_independent {
class clock {
private:
    const int minutes;
public:
    explicit clock(int minutes);
    static clock at(int hours, int minutes = 0);
    clock plus(int ms) const noexcept;
    clock minus(int ms) const noexcept;
    bool operator==(const clock &other) const noexcept;
    bool operator!=(const clock &other) const noexcept;
    explicit operator std::string() const;
};

}  // namespace date_independent

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif