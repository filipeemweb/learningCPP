// Condition to make sure it is implemented just once
#ifndef HANGTIC_GAME
#define HANGTIC_GAME

const int MAX = 30;

// All header files needed to run all aplications
#include <iostream>
#include <cctype>
#include <string>
#include <array>
#include <limits>

// Hangman`s functions
void askMystery();
int checkCorrectiness(char &let);
void drawGallows();
void checkMatching();
int run_hangman(int a);
void reset_hang();

// TicTacToe`s functions
void drawBoard();
int checkWinner();
int run_tic(int a);
void reset_tic();

#endif