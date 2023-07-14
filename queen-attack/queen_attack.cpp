#include "queen_attack.h"
#include <sstream>


queen_attack::chess_board::chess_board(const square &white, const square &black) : 
                                       white_queen { white }, black_queen { black } 
{
    if (black_queen == white_queen) {
        throw std::domain_error("Both queens on same square");
    }
    if (!on_board(white_queen) || !on_board(black_queen)) {
        throw std::domain_error("Some queen not on board");
    } 
}

const square &queen_attack::chess_board::black() const noexcept
    { return black_queen; }

const square &queen_attack::chess_board::white() const noexcept
    { return white_queen; }

queen_attack::chess_board::operator std::string() const {
    std::stringstream board;
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            if (file > 0) board << ' ';
            square position = {rank, file};
            if (position == black_queen) board << 'B';
            else 
            if (position == white_queen) board << 'W';
            else board << '_'; 
        }
        board << '\n';
    }
    return board.str();
}

bool queen_attack::chess_board::can_attack() const noexcept {
    int drank = abs(std::get<0>(white_queen) - std::get<0>(black_queen));
    int dfile = abs(std::get<1>(white_queen) - std::get<1>(black_queen));
    
    return drank * dfile == 0 || drank / dfile == 1;
}
