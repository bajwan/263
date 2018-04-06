---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Backtracking**

(Chapter 10 in Weiss)
---
With lack of a better option a problem can be solved via a brute-force search.

It is obvious (hopefully) that this is usually a slow way to solve a problem.

Backtracking offers a (usually not huge) improvement over a brute-force search, through the use of a technique called **pruning**.
---
Pruning occurs while we are solving a problem and realize that we can eliminate a large number of possible solutions at once.

Let's consider some examples.
---
The first example we will consider is a maze solving algorithm.  If we are given a starting position and an ending position in a maze, we could find a path through the maze by calculating every possible permutation of moves through the maze.

This would take awhile...
---
But what if we didn't need to calculate every possible way through the maze - what if we just needed to find one?

We could stat at the beginning point and pick a direction and taking a step.  Then we just keep doing that until we hit a wall.  When we hit a wall we go back a step and keep trying.
---
This is the crux of backtracking.  The reason this provides a performance improvement (when it does) is that by choosing a direction we are ignoring the other directions - we are pruning them.  If the direction we have chosen leads to a solution we never have to check the one we pruned.
---
How can we code this?  It seems like a lot to keep track of.  Every time we choose a direction we need to note where we were and what directions were already tried.

Any ideas?
---
If we choose directions in a particular order - say N, S, E, W each time - then we don't need a data structure to solve this problem.  We just rely on recursion.

Recursion will naturally keep track of our state for us.  We will call a function with our new direction.  If the direction leads to failure the function will return and the previous function will pick up where it left off.
---
The classic example of backtracking is the Eight Queens Problem.

In Chess the Queen can move in any direction and can move as many tiles as desired as long as they are all in the same direction.  A regular Chess board is an 8x8 array of tiles.  Can we place eight queens on the board so that they can't attack one another?
---
It turns out we can (in 92 different ways actually though many are symmetries to others).

But how can we find a solution?
---
Our algorithm looks like this:

- Start in the first tile.
- If the queens are all placed on tiles, return true.
- Try to place a queen in each row of the column.
  - If it can be placed here then choose this solution (update our board) and recursively check the next queen in the next column.
  - If that leads to a solution return true.
  - If it doesn't lead to a solution remove it from the board and try the next row.
- If we run out of rows then something in previous iterations went wrong.  Return false (backtrack!).
---
In general, all backtracking algorithms work similarly to this.  In fact, there is a general template to backtracking algorithms:

- Are we finished?  Return true.
- Crud, not finished.  See what we can try next.
  - If what we tried is a possibility, accept it and move on.
  - If that leads to a solution return true.
  - If it doesn't, remove the possibility and try something else.
- No more possibilities?  Maybe something went wrong before we got this far.  Return false (backtrack!).
---
