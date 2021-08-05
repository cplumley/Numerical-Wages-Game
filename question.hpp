#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
#include <vector>

class Question
{
private:
  std::string text;
  std::string answer;

public:
  Question();
  Question(std::string, std::string);
  std::string GetText();
  bool AnswerContainsDigit(char digit);
  std::string GetAnswerWithPlaceholders(std::vector<char>);
  bool AllDigitsGuessed(std::string);
};

#endif // !QUESTION_HPP
