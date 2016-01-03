//=============================================================================
//
// Assignment 5  :  Rock, Paper, Scissors Game
//
//
// Programmer    : Adnan Zejnilovic
// 
// Description   : This program plays a Rock,Paper,Scissors game with the user
//                 It keeps track of the number of wins for each player. When 
//                 one of the players reaches score of 10, that player wins and
//                 the game is over.
//                 This particular implementation uses static variables which are
//                 local to a function updateScoreAndAnnounceWinner. Please run it
//                 with a few debug cout statements to see how static variables 
//                 retain values between function calls.
//
//=============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global constants to represent rock,
// paper, or scissors.
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

// Global constants to represent the players/winners
const int COMPUTER = 1;
const int USER = 2;

// Global constant to represent the winning score upon which
// the game terminates
const int WINNING_SCORE = 10;


// Function Prototype
void displayMenu();
int getUserChoice();
int getComputerChoice();
int determineWinner(int, int);
void displayChoice(int);
bool updateScoreAndAnnounceWinner(int);
void displayScore(int, int);

int main()
{
    int userChoice;		    // To hold the user's choice
    int computerChoice;	    // To hold the computer's choice
    int winner;             // To hold the winner of a round
    bool gameOver = false;  // Flag signifying when we have a winner 
                       
    // Get the computer's choice.
    computerChoice = getComputerChoice();

    // Get the user's choice.
    userChoice = getUserChoice();

    while (!gameOver)
    {
        // Determine the winner and update the score.
        winner = determineWinner(userChoice, computerChoice);
        if (!updateScoreAndAnnounceWinner(winner))
        {
            // Get the computer's choice.
            computerChoice = getComputerChoice();

            // Get the user's choice.
            userChoice = getUserChoice();
        }
        else
        {
            gameOver = true;
        }
    }

    system ("PAUSE");
    return 0;
}

//======================================================
// Function    : displayMenu
// Date        : 10/20/2011
// Description :The displayMenu function displays the 
//              game menu. 
//======================================================
void displayMenu()
{
    cout << "Game Menu\n";
    cout << "---------\n";
    cout << "1) Rock\n";
    cout << "2) Paper\n";
    cout << "3) Scissors\n";
    cout << "Enter your choice: ";
}

//==================================================================
// Function    : getComputerChoice
// Date        : 10/20/2011
// Description : The getComputerChoice function returns 
// the computer's game choice. It returns 1 for rock (via the ROCK
// constant), or 2 for paper (via the PAPER constant),
// or 3 for scissors (via the SCISSORS constant).
//==================================================================
int getComputerChoice()
{
    // Get the system time so we can use it
    // to seed the random number generator.
    unsigned seed = time(0);

    // Use the seed value to seed the random
    // number generator.
    srand(seed);

    // Generate a random number in the range of 1-3.
    int number = 1 + rand() % 3;

    // Return the random value.
    return number;
}

//==================================================================
// Function    : getUserChoice
// Date        : 10/20/2011
// Description : The getUserChoice function displays a menu allowing
// the user to select rock, paper, or scissors. The
// function then returns 1 for rock (via the ROCK
// constant), or 2 for paper (via the PAPER constant),
// or 3 for scissors (via the SCISSORS constant).
//==================================================================
int getUserChoice()
{
    int choice;	// To hold a menu choice

    // Display the menu.
    displayMenu();
    cin >> choice;

    // Validate the choice.
    while (choice < 1 || choice > 3)
    {
        cout << "Invalid selection. Enter 1, 2, or 3: ";
        cin >> choice;
    }

    // Return the choice.
    return choice;
}

//==================================================================
// Function    : determineWinner 
// Date        : 10/20/2011
// Description : The determineWinner function accepts the user's
// game choice and the computer's game choice as
// arguments and displays a message indicating
// the winner.
//==================================================================
int determineWinner(int user, int computer)
{
    // Display the choices.
    cout << "You selected: ";
    displayChoice(user);
    cout << "The computer selected: ";
    displayChoice(computer);

    // variable to track who won the round
    int roundWinner = -1;

    if (user == ROCK)
    {
        if (computer == SCISSORS)
        {
            cout << "YOU win! Rock smashes scissors.\n";
            roundWinner = USER;
        }
        else if (computer == PAPER)
        {
            cout << "Computer wins! Paper wraps rock.\n";
            roundWinner = COMPUTER;
        }
        else
            cout << "Tie. No winner.\n";
    }
    else if (user == PAPER)
    {
        if (computer == SCISSORS)
        {
            cout << "Computer wins! Scissors cuts paper.\n";
            roundWinner = COMPUTER;
        }
        else if (computer == ROCK)
        {
            cout << "YOU win! Paper wraps scissors.\n";
            roundWinner = USER;
        }
        else
            cout << "Tie. No winner.\n";
    }
    else if (user == SCISSORS)
    {
        if (computer == ROCK)
        {
            cout << "Computer wins! Rock smashes scissors.\n";
            roundWinner = COMPUTER;
        }
        else if (computer == PAPER)
        {
            cout << "YOU win! Paper wraps scissors.\n";
            roundWinner = USER;
        }
        else
            cout << "Tie. No winner.\n";
    }
    else
    {
        cout << "Error condition detected!\n";
    }

    return roundWinner;
}

//====================================================================
// Function    : updateScoreAndAnnounceWinner
// Date        : 10/20/2011
// Description : The updateScore function accepts an integer argument 
// for the winner. Internally it uses 2 static variables to keep track
// of computerScore and userScore. Because of these static variables,
// we need to call displayScore as outside of this function we would
// not have access to these variables. The function also determines 
// whether either of the players(computer, user) has reached the 
// winning score. If so, then it returns true (bool) to its caller). 
//====================================================================
bool updateScoreAndAnnounceWinner(int winner)
{
    bool isWinner = false;
    static int computerScore = 0;
    static int userScore = 0;
    
    if (winner == COMPUTER)
    {
        computerScore += 1;
        if (computerScore == WINNING_SCORE)
        {
           cout << "GAME OVER"<< endl;
           cout << "The COMPUTER is the winner!" << endl;
           isWinner = true;
        }
    }
    else if (winner == USER)
    {
         userScore +=1;
         if (userScore == WINNING_SCORE)
         {
            cout << "GAME OVER"<< endl;
            cout << "YOU are the winner!" << endl;
            isWinner = true;
         }
    }
    
    displayScore(userScore, computerScore);
    return isWinner;
}

//====================================================================
// Function    : displayChoice  
// Date        : 10/20/2011
// Description : The displayChoice function accepts an integer
// argument and displays rock, paper, or scissors.
//====================================================================
void displayChoice(int choice)
{
    if (choice == ROCK)
        cout << "Rock\n";
    else if (choice == PAPER)
        cout << "Paper\n";
    else if (choice == SCISSORS)
        cout << "Scissors\n";
    else
        cout << "Error condition detected!\n";
}
//====================================================================
// Function    : displayScore  
// Date        : 10/20/2011
// Description : The displayScore function accepts two integer
// arguments and displays current score
//====================================================================
void displayScore(int user, int computer)
{
        cout << "----------------" << endl;
        cout << "USER : COMPUTER" << endl;
        cout << user << "    :      " << computer << endl;
        cout << "----------------" << endl;
}
