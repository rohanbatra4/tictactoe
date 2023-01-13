#include <stdio.h>

char board[3][3] = {{ ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' }};

void printBoard() { // prints the board
    printf("\n"); // print a blank line
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]); // print the first row
    printf("---+---+---\n"); // print the first row separator
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]); // print the second row
    printf("---+---+---\n"); // print the second row separator
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]); // print the third row
}

int checkForWin() { // returns 1 if there is a win, 0 otherwise
    // check rows
    for (int row = 0; row < 3; row++) { // for each row
        if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) // if the row is all the same and not empty
            return 1; // return 1 (true)
    }
    // check columns
    for (int col = 0; col < 3; col++) { // for each column
        if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) // if the column is all the same and not empty
            return 1; // return 1 (true)
    }
    // check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) // if the diagonal is all the same and not empty
        return 1; // return 1 (true)
    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) // if the diagonal is all the same and not empty
        return 1; // return 1 (true)
    return 0; // return 0 (false)
}

int main() {
    int x, y; // coordinates
    char player = 'X'; // start with player X
    int moves = 0;
    while (moves < 9) { // infinite loop
        printf("Player %c, enter x and y coordinates separated by space: ", player); // prompt the user
        scanf("%d%d", &x, &y); // read the coordinates
        x--; // convert from 1-3 to 0-2
        y--; // convert from 1-3 to 0-2
        if (x < 0 || x > 2 || y < 0 || y > 2) { // if the coordinates are invalid
            printf("Invalid coordinates. Try again.\n"); // if the coordinates are invalid
            continue; // go back to the beginning of the while loop
        }
        if (board[x][y] != ' ') { // if the cell is not empty
            printf("Cell already filled. Try again.\n"); // if the cell is not empty
            continue; // go back to the beginning of the while loop
        }
        board[x][y] = player; // set the cell to the current player
        printBoard(); // print the board
        if (checkForWin()) { // check for win
            printf("Player %c wins!\n", player); // print the winner
            break; // exit the while loop
        }
        player = (player == 'X') ? 'O' : 'X'; // switch players
        moves++;
    }
    if (moves == 9) { // if there are no more moves
        printf("Tie game!");
    }
    return 0; // exit program
}

