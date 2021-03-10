game: game.o Hangman.o TicTacToe.o
	g++ game.o Hangman.o TicTacToe.o -o game

game.o: game.cpp
	g++ -c game.cpp -std=c++11

Hangman.o: Hangman.cpp
	g++ -c Hangman.cpp -std=c++11

TicTacToe.o: TicTacToe.cpp
	g++ -c TicTacToe.cpp -std=c++11

clean: 
	rm *.o game


	