#include <string>

namespace log_line {

    [[nodiscard]]
    auto message(const std::string &line) noexcept -> std::string {
        int msg_start = line.find(':') + 2;
        return line.substr(msg_start);
    }
    [[nodiscard]]
    auto log_level(const std::string &line) noexcept -> std::string {
        int log_level_start = line.find("[") + 1;
        int log_level_end = line.find("]:") - 1;
        return line.substr(log_level_start, log_level_end);
    }
    auto reformat(const std::string &line) noexcept -> std::string {
        std::string level = "(" + log_level(line) + ")";
        return message(line) + " " + level;
    }
   
} // namespace log_line


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif
