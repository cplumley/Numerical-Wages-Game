#include <iostream>
#include <sstream>
#include "question_bank.hpp"

using namespace std;

QuestionBank::QuestionBank()
{
  string filename = GetFile();
  ValidateAndOpenFile(filename);
  LoadQuestions();
}

QuestionBank::QuestionBank(string filename)
{
  ValidateAndOpenFile(filename);
  LoadQuestions();
}

void QuestionBank::LoadQuestions()
{
  string line;
  while (getline(questionsFile, line))
  {
    if (!line.empty())
    {
      string answer, text;
      istringstream tmp(line);

      tmp >> answer;
      tmp.ignore();

      getline(tmp, text);

      Question new_question(text, answer);

      questions.push_back(new_question);
    }
  }
}

Question QuestionBank::GetNextQuestion()
{
  Question next_question = questions[0];

  this->questions.erase(questions.begin());

  return next_question;
}

void QuestionBank::ValidateAndOpenFile(string filename)
{
  questionsFile.open(filename);

  if (!questionsFile.is_open())
  {
    string new_filename = GetFile();
    ValidateAndOpenFile(new_filename);
  }
}

string QuestionBank::GetFile()
{
  string filename;
  std::cout << "\nMissing or invalid filename. Please try again.\n\n"
            << "Please enter the name of the file containing your questions: ";
  std::cin >> filename;

  return filename;
}