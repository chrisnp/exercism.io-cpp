#include "scrabble_score.h"

using namespace std;

int scrabble_score::score(const string& word) {

  int score {0};
  
  for (auto c : word) {
    score += 
        LETTER_SCORES[toupper(c) - 'A'];
  }

  return score;
}
