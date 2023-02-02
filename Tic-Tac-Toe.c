#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int won_game();
char curr_player_res();
void print_puzzle_board();
int mini_max_algo();
void player_puzz_move();
void computer_puzz_move();
void curr_player_choice();
void print_results();


//Main function to print results, validate game and take inputs from players choice.
int main() {
    int puzz_board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    print_puzzle_board(puzz_board);
    curr_player_choice(puzz_board);
    won_game(puzz_board);
    print_results(puzz_board);
}


//A function to validate if game is completed or not.
//If the return value is 0 then its a draw or else either computer will win or the player
int won_game(int puzz_board[9]) {
    unsigned win_moves[8][3] = {{0,4,8},{2,4,6},{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(puzz_board[win_moves[i][0]] != 0 &&
        puzz_board[win_moves[i][0]] == puzz_board[win_moves[i][1]] &&
        puzz_board[win_moves[i][0]] == puzz_board[win_moves[i][2]])
            return puzz_board[win_moves[i][2]];
    }
    return 0;
}


//A function to return the character string for current player.
//If the return value is X then the space is filled by the player, if its O the space is filled by the computer.
//If the value is empty space ' ' then the space is empty in the grid.
char curr_player_res(int p) {
    if (p == -1) {
        return 'X';
    }

    if (p == 0) {
        return ' ';
    }

    return 'O';
}


//To print the tic-tac-toe puzzle board in the terminal.
void print_puzzle_board(int puzz_board[9]) {
    printf(" %c | %c | %c\n",curr_player_res(puzz_board[0]),curr_player_res(puzz_board[1]),curr_player_res(puzz_board[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",curr_player_res(puzz_board[3]),curr_player_res(puzz_board[4]),curr_player_res(puzz_board[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",curr_player_res(puzz_board[6]),curr_player_res(puzz_board[7]),curr_player_res(puzz_board[8]));
}


//The main mini max recursive algorithm to check for optimal moves played by the computer.
int mini_max_algo(int puzz_board[9], int curr_player) {
    int winner = won_game(puzz_board);
    if(winner != 0) return winner*curr_player;

    int curr_pl_move = -1;
    int curr_pl_score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(puzz_board[i] == 0) {
            puzz_board[i] = curr_player;
            if(-mini_max_algo(puzz_board, curr_player*-1) > curr_pl_score) {
                curr_pl_score = -mini_max_algo(puzz_board, curr_player*-1);
                curr_pl_move = i;
            }
            puzz_board[i] = 0;
        }
    }
    if(curr_pl_move == -1) return 0;
    return curr_pl_score;
}


//The function to take players input from the terminal and update the puzzle board and check if the move made by the player is valid or not.
void player_puzz_move(int puzz_board[9]) {
    printf("Please enter your move in the blank space [0-8]");
    printf("\n");
    int player_move = 0;
    scanf("%d", &player_move);
    if (player_move < 0 || player_move > 8) {
        printf("Invalid move - please enter a valid value [0-8]");
        printf("\n");
        exit(0);
    }
    if (puzz_board[player_move] != 0) {
        printf("The current space is already occupied, please enter a valid move");
        printf("\n");
        exit(0);
    }
    puzz_board[player_move] = -1;
    print_puzzle_board(puzz_board);
}


//Function to update puzzle board by the moves made by the computer.
void computer_puzz_move(int puzz_board[9]) {
    int curr_pl_move = -1;
    int curr_pl_score = -2;
    int i = 0;
    while (i < 9) {
        if(puzz_board[i] == 0) {
            puzz_board[i] = 1;
            int tempScore = -mini_max_algo(puzz_board, -1);
            puzz_board[i] = 0;
            if(tempScore > curr_pl_score) {
                curr_pl_score = tempScore;
                curr_pl_move = i;
            }
        }
        ++i;
    }
    puzz_board[curr_pl_move] = 1;
    printf("Computers move");
    printf("\n");
    print_puzzle_board(puzz_board);
}


//Function to take inputs from the player and run player and computer chances alternatively
void curr_player_choice(int puzz_board[9]) {
    printf("Computer move 'O', Your move 'X'");
    printf("\n");
    printf("Would you like to play 1st or 2nd");
    printf("\n");
    int current_player = 0;
    scanf("%d",&current_player);
    printf("\n");
    if (current_player < 1 || current_player > 2) {
        printf("Invalid selection, please select valid options - 1/2");
        exit(0);
    }
    int curr_turn;
    for (curr_turn = 0; curr_turn < 9 && won_game(puzz_board) == 0; ++curr_turn) {
        if ((curr_turn + current_player) % 2 == 0) {
            //Computer moves function
            computer_puzz_move(puzz_board);
        } else {
            //Player moves function
            player_puzz_move(puzz_board);
        }
    }
}

//Function to print end results - Main Outcome of the game
void print_results(int puzz_board[9]) {
    int curr_score = won_game(puzz_board);
    if (curr_score == 0) {
        printf("Its a draw.\n");
    } else if (curr_score == 1) {
        printf("Computer has won!!! You lose.\n");
    } else {
        printf("Congratulations!!!! You won the game.\n");
    }
    exit(0);
}

