/*
 * Programmer : Bernice Templeman
 * COP1334
 * Homework #
 *
 * Description:
 * Rock, Paper, Scissors
 * Player vs Computer
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Constants
const int ROCK = 1;                        // Rock
const int PAPER = 2;                       // Paper
const int SCISSORS = 3;                    //Scissors

const int COMPUTER = 1;                    //  winner Computer
const int PLAYER = 2;                      // winner PLAYER
const int TIE = 3;                         // TIE

const int GAMENUM = 10;                    // first to win 10 rounds wins game
const int MINCHOICE = 1;                   // min choice for random function
const int MAXCHOICE = 3;                   // max choice for random function

// function prototypes
void getComputerChoice(int&);               // get Computer Choice-pass by reference
void getUserInput( int&);                   // get User Choice -pass by reference
void displayMenu();                         // display Menu
int compareChoices(int, int);               // compare Choice -pass by value
void updateScore(int, int&, int&, int &);   // update score - pass by value & reference
void displayResults( int, int, int);        // display result - pass by value
void displayScores( int, int);              // display scores - pass by value
void displayWinnerOfGame(int);              // display winner of Game - pass by value

int main()
{

    int userChoice;                         // user choice
    int computerChoice;                     // computer choice
    int winnerOfRound = 0;                  // winner of current round
    int winnerOfGame = 0;                   // winner of game (win 10 rounds)
    int computerScore = 0;                  // computer score accumupator
    int playerScore = 0;                    //USER SCORE ACCUMULATOR

    //LOOP until we have a game winner
    while ( winnerOfGame == 0)
    {

       getComputerChoice(computerChoice);   // call function to get computer choice
       displayMenu();                       // call the function to display menu
       getUserInput(userChoice);            // call the function to get userInput (pass by reference)

        //check for valid user choice
        if ((userChoice < MINCHOICE) || (userChoice >MAXCHOICE))
        {
            //invalid choice- display error message
            cout << "please enter 1, 2, or 3 only!" << endl;
        }

        //user made a valid choice
        else
        {
            //call function to compare choices & get winner ofround
            winnerOfRound = compareChoices(computerChoice, userChoice);

            //call function to update score
            updateScore(winnerOfRound, computerScore, playerScore, winnerOfGame);

            //call function to display results
            displayResults(computerChoice,userChoice, winnerOfRound);

            // call function to display scores
            displayScores(playerScore, computerScore);

        }//end else valid choice

    }//end while no winnerOfGame

    //CALL FUNCTION to display winner of Game
    displayWinnerOfGame(winnerOfGame);

    return 0;
}


void getUserInput(int& n2)
{
    cin >> n2;
}

void getComputerChoice(int& n1)
{
  srand(time(NULL));
  n1 = rand() %MAXCHOICE + MINCHOICE;

}

int compareChoices(int computerchoice, int userchoice)
{
    int winnerOfRound;
    if (computerchoice == userchoice)
    {
        winnerOfRound = TIE;
    }
    else if ( computerchoice == ROCK)
    {
        if (userchoice == SCISSORS)
        {
            winnerOfRound = COMPUTER;
        }
        else //userchoice == PAPER
        {
            winnerOfRound = PLAYER;
        }
    }
    else if (computerchoice == PAPER)
    {
        if (userchoice==ROCK)
        {
            winnerOfRound = COMPUTER;
        }
        else //userchoice == SCISSORS
        {
            winnerOfRound = PLAYER;
        }
    }
    else if (computerchoice == SCISSORS)
    {
        if (userchoice==ROCK)
        {
            winnerOfRound = PLAYER;
        }
        else //userchoice == PAPER
        {
            winnerOfRound = COMPUTER;
        }
    }

    return winnerOfRound;
}

void updateScore(int winnerOfRound, int& computerScore, int& playerScore, int& winnerOfGame)
{
   if (winnerOfRound == COMPUTER)
   {
      computerScore++;
      if (computerScore == GAMENUM)
         winnerOfGame = COMPUTER;
   }
   else if (winnerOfRound == PLAYER)
   {
      playerScore++;
      if(playerScore == GAMENUM)
         winnerOfGame = PLAYER;
   }
}

//display menu
void displayMenu()
{
    cout << "Game Menu:" << endl;
    cout << "_________" << endl;
    cout << "1. Rock " << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "Enter Your Choice: ";
}

//display results
void displayResults(int computerChoice,int userChoice, int winnerOfRound)
{
    //display choices
    cout << "You Selected: "<<  userChoice << endl;
    cout << "The Computer Selected: " << computerChoice << endl;

    //Display Winner of Round
    if (winnerOfRound == COMPUTER )
    {
        cout << "The Computer Wins!" << endl;

            //display logic
            switch (computerChoice)
            {
            case 1:
                if( userChoice == SCISSORS)
                    cout << "Rock Smashes Scissors"<< endl;
                else
                    cout << "Paper Wraps Rock" << endl;
              break;
            case 2: //
                if(userChoice == SCISSORS)
                    cout << "Scissors Cut Paper" << endl;
                else
                     cout << "Paper Wraps Rock" << endl;
              break;
            case 3:
                if( userChoice == PAPER)
                    cout << "Scissors Cut Paper" << endl;
                else
                    cout << "Rock Smashes Scissors"<< endl;
             break;
             }
    }

    else if (winnerOfRound == PLAYER)
    {
        cout << "You Win!" << endl;

        switch (userChoice)
        {

            case 1: //ROCK
                if( computerChoice == SCISSORS)
                    cout << "Rock Smashes Scissors"<< endl;
                else
                    cout << "Paper Wraps Rock" << endl;
              break;
            case 2: //PAPER
                if(computerChoice == SCISSORS)
                    cout << "Scissors Cut Paper" << endl;
                else //ROCK
                     cout << "Paper Wraps Rock" << endl;
              break;
            case 3://SCISSORS
                if( computerChoice == PAPER)
                    cout << "Scissors Cut Paper" << endl;
                else //ROCK
                    cout << "Rock Smashes Scissors"<< endl;
             break;
        }
     }
    else if (winnerOfRound == TIE)
    {
        cout << "Tie" << endl;
    }
}

//display scores
void displayScores(int userScore, int computerScore)
{
   cout << "USER : COMPUTER" << endl;
   cout << "_______________" << endl;
   cout << "  "<< userScore << " :   "<< computerScore <<endl;
}

//display winner of game
void displayWinnerOfGame(int winnerOfGame)
{
    if (winnerOfGame == COMPUTER)
     cout << "Winner of Game: COMPUTER"<< endl;
    else
        cout << "Winner of Game: YOU"<< endl;
}
