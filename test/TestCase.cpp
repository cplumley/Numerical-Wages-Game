// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch/catch.hpp"
#include "../question.hpp"
#include "../question_bank.hpp"
#include "../game.hpp"

TEST_CASE("Test Question object. PASS.")
{
  std::vector<char> guesses;

  // Create a Question
  Question q = Question("Foo?", "123");

  // Verify that initial value checks out
  REQUIRE(q.GetText() == "Foo?");
  REQUIRE(q.GetAnswerWithPlaceholders(guesses) == "___");

  // User guessing first digit
  guesses.push_back('1');
  REQUIRE(q.AnswerContainsDigit('1'));
  REQUIRE(q.GetAnswerWithPlaceholders(guesses) == "1__");

  // Verify that user hasn't "won" yet
  std::string placeholderString = q.GetAnswerWithPlaceholders(guesses);
  REQUIRE(!q.AllDigitsGuessed(placeholderString));

  // Complete guessing
  guesses.push_back('2');
  guesses.push_back('3');
  REQUIRE(q.GetAnswerWithPlaceholders(guesses) == "123");

  placeholderString = q.GetAnswerWithPlaceholders(guesses);
  REQUIRE(q.AllDigitsGuessed(placeholderString));
}

TEST_CASE("Test QuestionBank object. PASS.")
{
  QuestionBank questions("questions.txt");
  Question q = questions.GetNextQuestion();
  REQUIRE(q.GetText() != "");
}

TEST_CASE("Test Game object. PASS.")
{
  QuestionBank *questions = new QuestionBank("questions.txt");
  Game game = Game(questions);
  REQUIRE(game.GetCurrentScore() == 200);

  game.SetWager(99);
  game.AdjustPoints(true); // winner
  REQUIRE(game.GetCurrentScore() == 299);

  game.SetWager(50);
  game.AdjustPoints(false); // loser
  REQUIRE(game.GetCurrentScore() == 249);

  game.SetWager(77);
  REQUIRE(game.GetWager() == 77);

  game.SetWager(-77);
  REQUIRE(game.GetWager() == 1);

  game.SetWager(1000);
  REQUIRE(game.GetWager() == 249); // user only has 249 points after above operations
}

// Compile & run:
// make clean test
