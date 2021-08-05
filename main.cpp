#include <iostream>
#include <thread>
#include <chrono>
#include "game.hpp"
#include "question_bank.hpp"

using namespace std;

// Declare Functions
void welcome();
void play();
bool keepPlaying();

int main()
{
  welcome();

  do
  {
    play();
  } while (keepPlaying());

  cout << "\nThank you for playing! Good bye\n";
}

//////////////////////////
// Function Definitions //
//////////////////////////

void welcome()
{
  int time = 200;
  for (int i = 0; i < 5; ++i)
  {

    this_thread::sleep_for(chrono::milliseconds(time));
    system("clear");
    cout << "|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-||\n"
         << "||-|-|-                        |-|-|-|\n"
         << "|-|-|-|       Welcome  to      -|-|-||\n"
         << "||-|-|-    Numerical  Wagers   |-|-|-|\n"
         << "|-|-|-|                        -|-|-||\n"
         << "||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|\n\n";
    this_thread::sleep_for(chrono::milliseconds(time));
    system("clear");
    cout << "||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|\n"
         << "|-|-|-|                        -|-|-||\n"
         << "||-|-|-       Welcome  to      |-|-|-|\n"
         << "|-|-|-|    Numerical  Wagers   -|-|-||\n"
         << "||-|-|-                        |-|-|-|\n"
         << "|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-||\n\n";
  }
}

void play()
{
  string filename;
  cout << "Please enter the name of the file containing your questions: ";
  cin >> filename;

  QuestionBank questions(filename);
  Game game(&questions);

  for (int round = 1; round <= 3 && game.GetCurrentScore() != 0; ++round)
  {
    cout << "\nRound " << round << endl;

    game.AskQuestion();
  }
  cout << "--- Game over! ---\n\n"
       << "Final Score: " << game.GetCurrentScore() << endl
       << "------------------\n\n";
}

bool keepPlaying()
{
  int input;

  cout << "\nWould you like to:\n"
       << "1. Play a new game\n"
       << "2. Quit the game\n"
       << "Please make a selection: ";

  cin >> input;

  return input == 1 ? 1 : 0;
}