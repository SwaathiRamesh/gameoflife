# gameoflife
Conway's Game of Life
This is a simple demonstration of the Game of Life system.
When given the binding matrix, the pattern of the live cells and the number of iterations at the beginning,the program generates the outcomes according to the Game of Life Rules:
The initial pattern is the first generation. The second generation evolves from applying the rules simultaneously to every cell on the game board, i.e. births and deaths happen simultaneously. Afterwards, the rules are iteratively applied to create future generations. For each generation of the game, a cell's status in the next generation is determined by a set of rules. These simple rules are as follows:

1.If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors
2.If the cell is dead, then it springs to life only in the case that it has 3 live neighbors
( Explanation of Rules taken from http://www.math.cornell.edu/~lipa/mec/lesson6.html )
