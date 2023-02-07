***To Compile the program run following commands:***
* gcc -o Tic-Tac-Toe Tic-Tac-Toe.c

***To run:***
* ./Tic-Tac-Toe

***Decription***
* The game is implemented in a 3x3 grid where two players are playing against each other
to win by making their optimal moves. In this puzzle one opponent is a computer
(considered as a bot) and the other opponent is a player (a person who gives manual
inputs). Computer moves are shown as ‘X’ and player moves are ‘O’. Each player can
make their move against each other alternatively. The game ends when the complete
puzzle (3x3 grid) is filled with the player moves or when one of the players wins. There
can be 3 possible outcomes - ‘Draw’, ‘Computer Wins’ or ‘Player Wins’.

* The outcome can be decided by the position of the ‘X’ or ‘O’ in the puzzle. There will be
a winner when the alignment with the same character (‘X’ or ‘O’) matches either -
horizontally, vertically or diagonally. There are many conditions in the puzzle where
moves made by one player cannot be overridden by the other or once a move is made,
one cannot undo it.

* This puzzle is implemented using the Minimax algorithm where computer moves are
coded in such a way that it will check all possible moves made by the opponent and will
decide the best move (optimal solution) against the opponent where the best case
scenario is when the ‘computer Wins’ and worst case is ‘Draw’.

***Objective***
* The main objective of this puzzle is to design and implement a minimax algorithm in
such a way that Computer will make its best move by checking all the optimal solutions
possible and win against a human player. This is done by following all the rules for the
Tic-Tac-Toe puzzle and giving the best outcome which includes a win for the computer.

***Program Output***

* CASE 1 - DRAW

![image](https://user-images.githubusercontent.com/41941282/217129543-3fc59af8-2265-4a9e-ae8d-96693ae87063.png)

* CASE 2 - Computer Wins

![image](https://user-images.githubusercontent.com/41941282/217129723-a3be42a3-2033-4748-be8b-8fc5c23ea8d9.png)

