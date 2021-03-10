// Tic tac toe game project
#include "hang_tic.h" // main library

std::array<char, 10> board = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
std::array<int, 9> flag_t = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int player = 1, choice = 0,  winner = -1;
char mark = 'X';

// Game begining
int run_tic(int a)
{
    if (a != 0)
    {
        reset_tic();
    }

    // Main game loop
    do
    {
        drawBoard();

        player = (player%2) ? 1 : 2; // Alternates players

        mark = (player == 1) ? 'X' : '0'; // Set the right marker for the right player

        std::cout << "  Player " << player << ", enter a number: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 9 && (flag_t[choice - 1] == 0)) // Tests game rules
        {
            board[choice] = mark;
            flag_t[choice - 1] = 1;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            player--;
        }

        drawBoard();

        winner = checkWinner();

        player++;

    } while (winner == -1);

    // Prints end game results
    if (winner == 0)
    {
        std::cout << "It`s a draw.\n\n";
    }
    else
    {
        std::cout << "Winner is: Player " << --player << "\n\n";
    }

    return 0;
}

// Graphycs
void drawBoard()
{
    std::system("clear");

    printf("\nX ---- Tic Tac Toe ---- O\n");
    printf("      _____________\n");
    printf("     |             |\n");
    printf("     |  %c | %c | %c  |\n", board[1], board[2], board[3]);
    printf("     | ----------- |\n");
    printf("     |  %c | %c | %c  |\n", board[4], board[5], board[6]);
    printf("     | ----------- |\n");
    printf("     |  %c | %c | %c  |\n", board[7], board[8], board[9]);
    printf("     |_____________|\n\n");
    printf("O --------------------- X\n\n");

    return;
}

// Game rules
int checkWinner()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < 9; i++) // Do not allow repeated numbers to repleace its predecesor
        {
            if (flag_t[i] == 0)
            {
                return -1;
            }
        }

        return 0;
    }
}

// Resets the game for another round
void reset_tic()
{
    std::array<char, 10> temp = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    board = temp;

    for (int i = 0; i < 9; i++)
    {
        flag_t[i] = 0;
    }
    player = 1;
    choice = 0;
    winner = -1;
    mark = 'X';

    return;
}