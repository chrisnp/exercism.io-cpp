#pragma once

#include <string>
#include <vector>
#include <map>

namespace grade_school {

typedef std::map<int, std::vector<std::string>> Roster;

class school {

public:
    Roster roster() const;
    void add(std::string student, int grade);
    std::vector<std::string> grade(int grade) const;
private:
    Roster school_;
};

}  // namespace grade_school

#define EXERCISM_RUN_ALL_TESTS