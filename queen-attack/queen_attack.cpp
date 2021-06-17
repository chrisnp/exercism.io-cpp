#include "queen_attack.h"
#include <sstream>

queen_attack::chess_board::chess_board(const square &white, 
                                       const square &black) : 
                                       white_queen { white }, 
                                       black_queen { black } {
    if (black_queen == white_queen) {
        throw std::domain_error("Both queens on same square");
    } 
}

const square &queen_attack::chess_board::black() const noexcept {
        return black_queen;
    }

const square &queen_attack::chess_board::white() const noexcept {
        return white_queen;
    }

queen_attack::chess_board::operator std::string() const {
    std::stringstream board;
    for (int r = 0; r < 8; r++) {
        for (int f = 0; f < 8; f++) {
            if (f > 0) board << ' ';
            square queen = {r, f};
            if (queen == black_queen) board << 'B';
            else 
            if (queen == white_queen) board << 'W';
            else board << '_'; 
        }
        board << '\n';
    }
    return board.str();
}

bool queen_attack::chess_board::can_attack() const noexcept {
    int delta_rank = abs(white_queen.first - black_queen.first);
    int delta_file = abs(white_queen.second - black_queen.second);
    
    return delta_rank * delta_file == 0 ||
           delta_rank / delta_file == 1;
}