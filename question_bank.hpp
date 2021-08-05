#ifndef QUESTION_BANK_HPP
#define QUESTION_BANK_HPP

#include <fstream>
#include "question.hpp"

class QuestionBank
{
private:
  std::vector<Question> questions;
  std::ifstream questionsFile;
  void LoadQuestions();
  void ValidateAndOpenFile(std::string);
  std::string GetFile();

public:
  QuestionBank();
  QuestionBank(std::string);
  Question GetNextQuestion();
  void ReadQuestion();
};

#endif // !QUESTION_BANK_HPP
