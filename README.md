Εxcercise 1 & 2
Construction of a program that solves the following search problem:
Consider a list of N positions in which the natural numbers from 1 to N have been placed (each number appearing exactly once) (e.g., [1,3,2,4,5], [2,1,4,5,3], etc., for N=5). Therefore, the state space corresponds to the permutations of the N natural numbers (from 1 to N). The final state is the state [1,2,...,N] (i.e., the numbers are placed in ascending order).
The initial state is defined by the user at the beginning of the program execution.
N is either defined within the program or given by the user at the beginning of the program execution.
The transition operators (i.e., the permissible actions in each state) are defined as follows:
Let a=[a1,...,aN] be a state. The application of the operator T(k) (where 2≤k≤N) on state a leads to a state b=[b1,...,bN] which is formed as follows: a is divided into two segments: aL=[a1,...,ak] (which includes the first k elements of a) and aR=[ak+1,...,aN] (which includes the remaining elements of a).
If k=N then aL=a and aR=[] (empty list). Let raL=[ak,...,a1] be the list obtained by reversing the order of the elements in aL. The state b=[b1,...,bN] is defined by the concatenation of raL and aR.
For example: the application of the operator T(2) on state a=[3,5,4,1,2] leads to state b=[5,3,4,1,2], the application of the operator T(4) on state a=[3,5,4,1,2] leads to state b=[1,4,5,3,2], and the application of the operator T(5) on state a=[3,5,4,1,2] leads to state b=[2,1,4,5,3]. Note that the operator T(1) results in b=a, which is not allowed since it does not lead to a different state. All transitions have a cost of 1.
Given any initial state (IS) defined by the user, we want the program to find the optimal sequence of actions to reach the final state (FS=[1,2,...,N]).
For the above problem, implement:
i) Uniform Cost Search (UCS) 
ii) A* search using the best possible admissible heuristic function h(n). You must explain in writing (in a text document report.pdf) why the function h(n) you devised is admissible. 
Examine different values of N as well as different initial states (IS). 
For each N and IS, apply both the UCS method and the A method so that you can compare the methods. Specifically, the program should print: a) the path, b) the cost of this path, and c) the number of expansions performed. In the text document (report.pdf), report your conclusions regarding the efficiency of A compared to UCS.**

Εxcercise 3
**Creation of a program that will play against a user in the following two-player turn-based game.
The game is played on an MxN grid. Each player has a piece that occupies one square on the grid. In the diagram below, piece A (MAX player) occupies the middle square of the first row, while piece B (MIN player) occupies the middle square of the last row.

![image](https://github.com/BourliEftychia/Artificial-Intelligence-project/assets/72252284/e5e6ba2d-5db9-411c-af42-1d92076d1972)

The black squares are those that the pieces have already visited or traversed and cannot be revisited by the pieces.
Each player can move their piece, under certain conditions, like a queen in chess: horizontally, vertically, and diagonally. You can set a limit on the movement (e.g., up to two positions).
The conditions for moving a piece are as follows:

A piece can only traverse white squares and can only be placed on a white square.
A piece cannot be placed on or pass through (during its movement) the square where the opponent's piece is located.
When a piece makes a move, the square from which it starts and the squares it traverses become black.

The player who has no valid move when it is their turn to play loses.

In the following example, piece A has three valid moves: (a) one position diagonally (up-right), (b) one position to the right, and (c) two positions to the right. Piece B has no valid moves. Consequently, MAX (piece A) wins.

![image](https://github.com/BourliEftychia/Artificial-Intelligence-project/assets/72252284/e2c1f3c3-73a5-4926-8d7e-6d6ce2366559)

Consider that 'MAX player' = program (piece A), 'MIN player' = opponent (piece B), and that MAX plays first. The MxN size of the board should be a parameter of the program (e.g., M=N=4).

First, define appropriate values for the end-state evaluations, then create the program to execute the game in which MAX must play optimally by executing the MINIMAX algorithm with the root being the current state to decide the move to make each time. (The implementation of MINIMAX should be done using recursion).

At the beginning of the program, the positions of A and B should be specified, as well as (optionally) some squares that should be initially black (to reduce the possible moves of the pieces).

At the beginning of the program code, state any assumptions you made regarding the allowed movements of the pieces.**

