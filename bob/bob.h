#pragma once

#include <string>

namespace bob {

    static const std::string RESPONSE_QUESTION { "Sure." };
    static const std::string RESPONSE_SHOUT { "Whoa, chill out!" };
    static const std::string RESPONSE_EMPHATIC { "Calm down, I know what I'm doing!" };
    static const std::string RESPONSE_SILENCE{ "Fine. Be that way!" };
    static const std::string RESPONSE_DEFAULT{ "Whatever." };
 
    std::string hey(const std::string &);

}  // namespace bob

#define EXERCISM_RUN_ALL_TESTS