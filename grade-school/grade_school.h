#pragma once

#include <string>
#include <vector>
#include <map>

namespace grade_school {

typedef std::map<int, std::vector<std::string>> Roster;

class school {

public:
    Roster roster() const;
    void add(string student, int grade);
    std::vector<std::string> grade(int grade) const;

private:
    

};

}  // namespace grade_school

#define EXERCISM_RUN_ALL_TESTS