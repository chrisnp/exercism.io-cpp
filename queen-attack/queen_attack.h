#pragma once

#include <string>
#include <utility>

typedef std::pair<int, int> square;

namespace queen_attack {
    
class chess_board {
    
public:
    explicit chess_board(
                const square &white = {0, 3}, 
                const square &black = {7, 3}
             );

    const square &white() const noexcept;
    const square &black() const noexcept;

    explicit operator std::string() const;
    bool can_attack() const noexcept;
    
private:
    square white_queen, black_queen;
};
}  // namespace queen_attack

#define EXERCISM_RUN_ALL_TESTS