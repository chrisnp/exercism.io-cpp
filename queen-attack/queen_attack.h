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

    explicit operator std::string() const;

    const square &black() const noexcept;
    const square &white() const noexcept;

    constexpr auto legal_position(square const& legal) noexcept -> bool {
        return 0 <= legal.first && 
               7 >= legal.first &&
               0 <= legal.second && 
               7 >= legal.second;
    }

    bool can_attack() const noexcept;
    
private:
    square white_queen, black_queen;
};
}  // namespace queen_attack

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif