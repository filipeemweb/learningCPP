// Hangman Game Project
#include "hang_tic.h"

//
char letter;
char word[MAX + 1], mystery[MAX + 1], stick[] = {'s', ' ', ' ', ' ', ' ', ' ', ' '};
int wordLenght, miss = 0, gameOver = 0, match = 0, played = 0; 
bool equal;

// Game begining
int run_hangman(int a) {
    
    if (a != 0)
    {
        reset_hang();
    }
    
    // Prompts the user for the word to be guessed for
    askMystery();

    // Makes the word not recognisable
    for (int j = 0; j < wordLenght; j++) {
        mystery[j] = '*';
    }

    // Main game loop
    do
    {
        
        drawGallows();

        std::cout << "Enter a letter: ";
        
        do
        {
            std::cin >> letter;
        } while (checkCorrectiness(letter) != 1);

        checkMatching();
    } while (gameOver == 0 && match < wordLenght);

    // Game ending
    if (gameOver == 1)
    {
        std::cout << "\nxxx GAME OVER xxxx\n";
        std::cout << "The word was: " << word << "\n\n";
    }
    else
    {
        std::cout << "\n>>>> Congrats! You won. <<<<\n";
        std::cout << "The word was: " << word << "\n\n";
    }

    return 0;    
}

// Promts user for the mystery word
void askMystery() {
    int i = 0;

    std::cout << "\nEnter a word (max 30 char): ";
    std::cin >> word;

    while (word[i] != '\0')
    {
        word[i] = tolower(word[i]);
        wordLenght++;
        i++;
    }
    std::cout << "\n\n";
}

// Tests guesses provided by the player for only a character
int checkCorrectiness(char &let)
{
    let = tolower(let);

    for (int i = 0; i < wordLenght; i++)
    {
        if (mystery[i] == let)
        {
            std::cout << "\b \b";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 0;
        }
    }

    return 1;
}

// Draws the gallow and update the stickman when the guessed letter is wrong 
void drawGallows() {
    std::system("clear"); // Clears the screen every time an update is made

    switch (miss)
    {
    case 0:
        stick[0] = 's';
        break;
    case 1:
        stick[1] = 'o';
        break;
    case 2:
        stick[2] = '/';
        break;
    case 3:
        stick[3] = '|';
        break;
    case 4:
        stick[4] = '\\';
        break;
    case 5:
        stick[5] = '/';
        break;
    case 6:
        stick[6] = '\\';
        gameOver = 1;
        break;   
    }
    
    std::cout << "--- Hangman Game ---\n";
    std::cout << "    ____\n";
    std::cout << "   |    |  " << 6 - miss << " lifes\n";
    std::cout << "   |    " << stick[1] << std::endl;
    std::cout << "   |   " << stick[2] << stick[3] << stick[4] << " " << wordLenght - match << " letters\n";
    std::cout << "   |   " << stick[5] << " " << stick[6] << "\n\n";

    std::cout << "        ";
        for (int i = 0; i < wordLenght; i++) {
            std::cout << mystery[i];
        }
        std::cout << "\n";
}

// Where the rules of the game are impremented
void checkMatching() {
    equal = false;

    for(int i = 0; i < wordLenght; i++) {
        if (word[i] == letter) { // If the guessed letter is equal to any letter of the Mystery word
            mystery[i] = letter; // we update on the screen all matches
            equal = true; // Used as a flag
            match++;
        }        
    }

    if (equal == false) {
        miss++;
    }
}

// used when creating another round
void reset_hang()
{
    letter = ' ';
    
    for (int i = 1; i < 7; i++)
    {
        stick[i] = ' ';
    }

    for (int i = 1; i < MAX + 1; i++)
    {
        word[i] = ' ';
    }

    for (int i = 1; i < MAX + 1; i++)
    {
        mystery[i] = ' ';
    }

    wordLenght = 0;
    miss = 0;
    gameOver = 0;
    match = 0;
    played = 0;

    return;
}