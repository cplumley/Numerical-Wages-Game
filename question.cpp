#include "question.hpp"

using namespace std;

Question::Question(string text, string answer)
{
  this->answer = answer;
  this->text = text;
}

string Question::GetText()
{
  return text;
}

bool Question::AnswerContainsDigit(char digit)
{
  return (answer.find(digit) != string::npos);
}

string Question::GetAnswerWithPlaceholders(vector<char> guesses)
{
  string answerWithPlaceholders;

  // TODO: Refactor code
  for (size_t i = 0; i < answer.length(); ++i)
  {
    bool isDigit = 0;
    for (size_t j = 0; j < guesses.size(); ++j)
    {
      if (answer[i] == guesses[j])
      {
        isDigit = 1;
        break;
      }
    }
    if (isDigit)
    {
      answerWithPlaceholders.push_back(answer[i]);
    }
    else
      answerWithPlaceholders += "_";
  }

  return answerWithPlaceholders;
}

bool Question::AllDigitsGuessed(string answerWithPlaceholders)
{
  for (size_t i = 0; i < answerWithPlaceholders.length(); ++i)
  {
    if (answerWithPlaceholders[i] == '_')
      return 0;
  }

  return 1;
}