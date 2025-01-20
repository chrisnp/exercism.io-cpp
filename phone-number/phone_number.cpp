#include "phone_number.h"

#include <stdexcept>
#include <regex>

// namespace phone_number {
phone_number::phone_number::phone_number(const std::string &number ) {
    auto pnumber = std::regex_replace(number, std::regex {R"(\D)"}, "");
    auto pnlength = pnumber.length();
    if (pnlength < 10) throw std::domain_error {"Less than 10 digits"};
    if (pnlength == 11)
        if (pnumber[0] != 1) 
            throw std::domain_error {"This should start with 1"};
    if (pnlength > 11) throw std::domain_error {"More than 11 digits" };
    if (pnlength != 10) pnumber = pnumber.substr(1);
    if (pnumber[0] == 0 || pnumber[0] == 1) 
        throw std::domain_error("Invalid Area Code");
    if (pnumber[3] == 0 || pnumber[3] == 1) 
        throw std::domain_error("Invalid Exchange Code");
    this->area_code = pnumber.substr(0, 3);
    this->exchange = pnumber.substr(3, 3) + "-" + pnumber.substr(6);
    this->number = pnumber;
    this->_formatted = "(" + this->_area + ")"
}


// }  // namespace phone_number
