---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**P vs. NP**
---
There are many, many problems that a computer can solve - given appropriate algorithms and time.  We need a way to classify the complexity of problems so that we know what a computer is and is not capable of.
---
For instance, there are problems that are unsolvable by a computer.  We call these problems **undecidable problems**.  The most famous of these is probably the **halting problem**.
---
The halting problem asks if it is possible to have compiler examine any arbitrary program and determine if the program will finish running.

For Turing Machines - which our model of computation is built on - the answer to this problem is no, a compiler cannot do this for any program.  Consider:
---
To solve this problem the compiler would need to have a routine that simulates the running of the algorithm in question.  The routine doing the examining would then stop simulating when the algorithm stopped running.  But if the algorithm never stops running, then the routine can never stop running either.
---
These undecidable problems are the hardest problems in computer science.  They exist outside the boundaries of what our (current) computers can do.
---
There are other problems in computer science that *might* be possible.

This is a **major** problem in Computer Science (and Mathematics in general).  There are substantial rewards for anyone who can answer this problem; it is called the P vs. NP problem.
---
The problem of P vs. NP is concerned with **complexity classes**.  An algorithm may be able to solve a problem in **polynomial time**; this means that the time it takes to solve the problem can be represented via a polynomial function that takes as input the size of the data.
---
For instance, we saw that Insertion Sort's runtime can be expressed via the polynomial O(n^2), where n is the size of the data input to the sorting function.  We assign these problems to the class **P**.
---
There are quite a few problems that cannot be solved in polynomial time (to our knowledge), but can be **verified** in polynomial time.  This means that given a possible solution we can verify the solution is correct in polynomial time.
---
If a problem can be verified in polynomial time we say it is of the class **NP**, which stands for "Non-deterministic polynomial time".
---
Let us be very clear moving forward that we understand this definition.  We aren't saying these problems can be solved in Non-deterministic polynomial time.  We are saying that a potential solution can be verified.
---
Consider the Sudoku problems we worked with earlier.  We saw that this is an extremely long-running algorithm.  We used backtracking to try and cut down (prune) the number of solutions but that was likely a small optimization.

This algorithm is non polynomial; there are number of empty squares ^ 9 possibilities.
---
So solving a sudoku puzzle is obviously not polynomial.  But verifying one is!  It is trivial to take some solution and check to see if it works.  We merely iterate of each cell and check to see if each the digit there is used in any other row, column, or block.  We can do this in O(n^2) time in fact!
---
We further divide NP problems though.

**NP-Hard** problems are the set of problems where any problem in NP can be reduced to one of the problems in this set in polynomial time.  These may not be NP.

**NP-Complete** is a complexity class where any problem in NP can be reduced to it in polynomial time, and solutions can be verified in polynomial time (it is also NP).
---
Yes, this is confusing.  Let's see this visually:

![P vs. NP (if P != NP)](./p-np/images/p-np-1.png)
