In combinatorial game theory, an impartial game is a game in which the allowable moves depend only on the position and not on which of the two players is currently moving, and where the payoffs are symmetric
    
In combinatorial game theory, a game is partisan (sometimes partizan) if it is not impartial. That is, some moves are available to one player and not to the other.
    
in an impartial game a state 
        a state is winning if any one move can go to a losing state 
        a state is losing if no move to a losing state exist aka all moves lead to winning state 
base case = loosing state equals when first player who moves loses 
from a winning state first player wins
from a losing state first player loses
     
example : https://www.youtube.com/watch?v=ndvoTQE92TQ&list=PLj6WGJe-RmYZ-yHrobuCZVjaKHpXTxZOJ 

game of nim : no heap -> losing = game 0 (first player who plays looses)

draw states accordingly and the DAG as well
    
    example : see image

note this is brute force is which we proceed in khans algorithm for all states and calculate win or loose for first player
        
        
To study grundy and stuff: