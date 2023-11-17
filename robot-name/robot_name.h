#pragma once
#include <string>

namespace robot_name {

class robot {

public:
    explicit robot();
    auto reset() -> void;
    auto name() const noexcept -> std::string const&;
private:
    std::string _name;
};

}  // namespace robot_name


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif