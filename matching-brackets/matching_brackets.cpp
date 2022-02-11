#include "matching_brackets.h"

#include <stack>
#include <stdexcept>

bool matching_brackets::check(std::string const &str) {
    constexpr auto closing_bracket = [](const char b) -> char {
        switch (b) {
            case '[': return ']';
            case '{': return '}';
            case '(': return ')';
            default : throw std::domain_error("invalid bracket");
        }
    };
    std::stack<char> stack {};
    for (auto ch : str) {
        switch (ch) {
            case '[':
            case '{':
            case '(':
                stack.push(closing_bracket(ch));
                break;
            case ']':
            case '}':
            case ')':
                if (stack.size() == 0 || stack.top() != ch) 
                    return false;
                stack.pop();
            default: continue;
        }
    }
    return stack.empty();
}
