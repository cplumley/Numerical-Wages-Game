#include <iostream>
#include <vector>
#include <string>
#include "game.hpp"

using namespace std;

Game::Game()
{
  questions = new QuestionBank;
  currentScore = 200;
}

Game::Game(QuestionBank *questions)
{
  this->questions = questions;
  this->currentScore = 200;
}

int Game::AskQuestion()
{
  Question q = questions->GetNextQuestion();
  StartRound(q);
  vector<char> guesses;
  int missed_guesses = 0;
  string a = q.GetAnswerWithPlaceholders(guesses);

  do
  {
    char input;
    cout << "\nCurrent Question: " << q.GetText() << endl
         << "Current Answer: " << a << endl
         << "Missed Guesses: " << missed_guesses << endl
         << "Please guess a digit: ";
    cin >> input;
    guesses.push_back(input);

    if (q.AnswerContainsDigit(input))
      a = q.GetAnswerWithPlaceholders(guesses);
    else
      missed_guesses += 1;
  } while (missed_guesses <= 2 && !q.AllDigitsGuessed(a));

  AdjustPoints(q.AllDigitsGuessed(a));
  return currentScore;
}

void Game::StartRound(Question question)
{
  int wager;
  cout << "Next Question: " << question.GetText() << endl
       << "Current Points: " << GetCurrentScore() << endl
       << "Please make a wager: ";
  cin >> wager;
  SetWager(wager);
}

void Game::AdjustPoints(bool isCorrect)
{
  if (isCorrect)
    currentScore += amountWagered;
  else
    currentScore -= amountWagered;
}

void Game::SetWager(int wager)
{
  if (wager < 1)
    wager = 1;
  else if (wager > currentScore)
    wager = currentScore;
  this->amountWagered = wager;
}

int Game::GetWager()
{
  return amountWagered;
}

int Game::GetCurrentScore()
{
  return currentScore;
}