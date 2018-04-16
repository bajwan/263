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
The halting problem asks if it is possible to have a compiler examine an arbitrary program and determine if the program will finish running.

For Turing Machines - which our model of computation is built on - the answer to this problem is no, a compiler cannot do this for every program.  Consider:
---
To solve this problem the compiler would need to have a routine that simulates the running of the algorithm in question.  The routine doing the examining would then stop simulating when the algorithm stopped running.  But if the algorithm never stops running, then the routine can never stop running either.
---
These undecidable problems are the hardest problems in computer science.  They exist outside the boundaries of what our (current) computers can do.
---
There are other problems in computer science that may be possible, but we don't know how long they might  take.

This is a **major** problem in Computer Science (and Mathematics in general).  There are substantial rewards for anyone who can answer this problem; it is called the P vs. NP problem.
---
The problem of P vs. NP is concerned with **complexity classes**.  An algorithm may be able to solve a problem in **polynomial time**; this means that the time it takes to solve the problem can be represented via a polynomial function that takes as input the size of the data.
---
For instance, we saw that Insertion Sort's runtime can be expressed via the polynomial O(n^2), where n is the size of the data input to the sorting function.  We assign these problems to the class **P**.
---
There are quite a few problems that cannot be solved in polynomial time (to our knowledge), but can be **verified** in polynomial time.  This means that given a possible solution we can verify the solution is correct in polynomial time.
---
If a problem can be verified in polynomial time we say it is of the class **NP**, which stands for "Nondeterministic polynomial time".
---
Nondeterministic models of computation might seem odd.  A normal computer can take one path of execution at a time, it has no choice as to what to choose next.  When we get to the end of the execution path we may or may not have the right answer.
---
A Nondeterministic machine can make choices, and will always make the best choice.  Obviously this doesn't exist, but it is still useful; it might be easier in some cases to model a solution to a problem with nondeterminism and then convert it to a deterministic model.
---
So let's get back to NP problems, and let us be very clear moving forward that we understand the definition of them.

We aren't saying these problems can be solved in nondeterministic polynomial time.  We are saying that a potential solution can be verified in polynomial time.
---
In general we do this by turning them into a yes/no problem (a decision problem).  Then, if we can prove that some given answer is correct in polynomial time, the problem is in NP.
---
For instance, if we had the 0/1 Knapsack problem we might change the problem statement from

>Given a set of n items with values and weights 1 to n, and a knapsack with capacity W, what is the maximum value the of the items we could carry?

To
---
>Given the above constraints, can a value of at least V be met without exceeding the weight W?
---
Consider the Sudoku problems we worked with earlier.  We saw that this is an extremely long-running algorithm.  We used backtracking to try and cut down (prune) the number of solutions but that was likely a small optimization.
---
A sudoku board of 9x9 may not be that bad, but as the size grows, this becomes a truly hard problem.

This algorithm is not polynomial; there are ```(number of possible values per square) ^ (number of empty squares)``` possibilities.
---
So solving a sudoku puzzle is obviously not polynomial.  But verifying one is!  It is trivial to take some solution and check to see if it works.  We merely iterate over each cell and check to see if the digit there is used in any other row, column, or block.  We can do this in O(n^2) time in fact!
---
We further divide NP problems though.

**NP-Hard** problems are the set of problems where any problem in NP can be reduced to one of the problems in this set in polynomial time.  These may not be NP themselves.

**NP-Complete** is a complexity class where any problem in NP can be reduced to it in polynomial time, and solutions can be verified in polynomial time (it is also NP).
---
Yes, this is confusing.  Let's see this visually:

![P vs. NP (if P != NP)](./p-np/images/p-np-1.png)
---
Now, the problem is that we don't know if the above image is correct - this is why this is an open problem in Mathematics and Computer Science.

It might look like this:
---
![P vs. NP (if P == NP)](./p-np/images/p-np-2.png)
---
What does this mean?

If P == NP this would imply that any problem that can be verified in polynomial time can also be solved in polynomial time.
---
This would change the world.  We would need to change a great deal of our security and cryptography, most "hard" things that we have computers do such as computer vision and speech recognition would become trivial, manufacture and transportation of goods could be perfectly optimized, drugs could be discovered faster, etc.
---
You can read more [here](https://cacm.acm.org/magazines/2009/9/38904-the-status-of-the-p-versus-np-problem/fulltext).

Unfortunately, theorists really don't believe that P == NP.  But, it hasn't been proven not to either so we keep trying.  There are million dollar prizes available for anyone who can provide a proof either way.
---
NP-Complete problems are the hardest problems in NP.  It turns out that any problem in NP can be reduced to an NP-complete problem via some polynomial transformations.

This means that if we could find a polynomial solution to one NP-complete problem we would have a polynomial solution to all of them.
---
There are quite a few problems that we already know are NP-complete.  Some of the more common are the:
---
Knapsack problem.  We've already discussed this one so we won't go into it here.
---
Hamiltonian Path problem.

Can we find a path in a graph that visits every vertex exactly once?
---
Traveling Salesman problem.

Given a list of cities and distances between each pair of cities, what is the shortest path a salesman could take that would visit every city and bring her back to the beginning?
---
Clique problem.

A clique in a graph is a subset of vertices such that every vertex is adjacent to the others.

The clique problem is the problem of finding the a K-sized clique in a graph.
---
Vertex cover problem.

What is the minimum set of vertices such that every edge is connected to a vertex in the set?
---
Independent set problem.

What is the largest subset of vertices from a graph such that none of the vertices are connected?
---
Graph Coloring problem.

What is the minimum number of colors we need so that we can color the vertices of a graph such that no connecting vertices have the same color?
---
And others.

We often need to prove that a problem is as hard as another problem, i.e. that we can't find a faster solution.  Since we know that any problem in NP can reduce to an NP-complete problem (since they are the hardest in NP), we can use this for our proof.
---
In order to perform this proof we first need some problem P1 that we already know is an NP-complete problem.  We will assume that P2 is in NP.  If we find some way to map the data from P1 to P2 that completes in polynomial time, we can use P2 to solve P1.
---
Since we know that P1 was NP-complete, we have now shown the P2 is also NP-complete.  This means that every problem in NP can reduce to P2 as well.
---
Let us consider an example.  Let's say we wanted to prove that the Traveling Salesman problem was NP complete (we already know it is now, but suppose we didn't).

We will define the problem as:
---
**Traveling Salesman Problem**

Given a complete graph, G = (V,E), with edge costs, and an integer K, is there a simple cycle that visits all vertices and has total cost ≤ K?
---
We know that the Traveling Salesman problem is in NP, since we can check a possible solution in polynomial time.

Given a solution, we merely need to complete the tour and see if our final distance is less than K.
---
To attempt to reduce the Hamiltonian Cycle problem to Traveling Salesman, we first find a polynomial reduction.  Here, we will create a new graph, G'.  G' will have the same vertices as G.  If some edge (v,w) was in G, we will give it a weight of 1 in G'.  If there was not a possible edge in G between some (v,w) we will create an edge in G' with weight 2.
---
We now choose the value of K to be |V|, which is the number of vertices in G.

It should be fairly obvious now that G has a Hamiltonian cycle if and *only if* G' has a traveling salesman path of weight |V|.
---?image=./p-np/images/reduction-1.png&size=50% auto
---
