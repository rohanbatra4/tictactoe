# Tic Tac Toe Game
This is a simple Tic Tac Toe game that allows two players to play the game on the command line. The game board is represented by a 3x3 2D array where each cell can contain either 'X', 'O', or ' '.

## How to Play
1. Compile and run the code on your command line.
2. Player X starts the game and takes the first turn.
3. Players take turns entering the x and y coordinates of the cell they want to fill. Coordinates range from 1 to 3.
4. The game board is printed after each move.
5. The game ends when one player gets three of their symbols in a row horizontally, vertically, or diagonally, or when all cells are filled with no winner.

## Function Descriptions
- `printBoard()`: prints the current state of the game board
- `checkForWin()`: checks if there is a winner and returns 1 if there is
