#pragma once

namespace phone_number {

using std::string;

struct phone_number {
    phone_number(const string&);
    string number() const;
    string area_code() const;
    string exchange() const;
    operator string() const;
    private:
        string _number;
        string _area;
        string _exchange;
        string _formatted;

};

}  // namespace phone_number


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif