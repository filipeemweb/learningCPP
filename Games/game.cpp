// Little game menu project
#include "hang_tic.h"

using std::cout;
using std::cin;
using std::system;

int main() 
{
    int choice;

    // Main game loop
    do
    {
        system("clear");

        // Value to reset the games after being played
        static int hangman = 0;
        static int tictactoe = 0;

        cout << "---- MENU ----\n\n";
        cout << "1: Hangman\n";
        cout << "2: Tic Tac Toe\n";
        cout << "0: Exit\n\n";

        cout << "Enter: ";
        cin >> choice;

        // The actual menu 
        switch (choice)
        {
        case 0:
            cout << "Thanks for playing!\n\n";
            return 0;
            break;
        case 1:
            run_hangman(hangman);
            hangman++;
            break;
        case 2:
            run_tic(tictactoe);
            tictactoe++;
            break;
        }
    } while (choice != 0);

    return 0;   
}