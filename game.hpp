#ifndef GAME_HPP
#define GAME_HPP

#include "question_bank.hpp"

class Game
{
private:
  QuestionBank *questions;
  int amountWagered;
  int currentScore;
  void StartRound(Question);

public:
  Game();
  Game(QuestionBank *);
  int AskQuestion();
  void AdjustPoints(bool);
  void SetWager(int);
  int GetWager();
  int GetCurrentScore();
};

#endif // !GAME_HPP