---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Greedy Algorithms**

(Chapter 10 in Weiss)
---
We now are studying some general types of algorithms.  It is important for us to be able to recognize the types of problems that can be solved with different types of algorithms, and to be able to generalize the solutions to other problems.
---
The first algorithm type we will discuss is **Greedy Algorithms**.  This class of algorithm works by going through computational phases, and choosing the best choice at the current time.
---
Because greedy algorithms are not concerned with the future they cannot always provide optimal solutions for every problem; to do that we need to know what the future might hold.  Greedy algorithms don't care about that.
---
Let's consider a simple example of a greedy algorithm.

In the U.S. we have the following coin denominations:

- dollar
- half dollar
- quarter
- dime
- nickel
- penny
---
If we are told to give people the smallest number of coins possible when we make change, this is an easy problem.  Let's say someone comes to our store and purchases a candy bar for $1.06 (after tax).  We need to give them back $0.94.  To do that with the least number of coins:
---
- Give as many quarters as we can (3)
- Give as many dimes as we can (1)
- Give as many nickels as we can (1)
- Give as many pennies as we can (4)

9 coins.

This algorithm is greedy because at each pass through it took as much as it could (or gave as much as it could) of one coin.
---
But what if we had the following coins instead?:

- dollar
- half dollar
- quarter
- eleven-cent piece
- dime
- nickel
- penny

Would this algorithm still work?
---
- Give as many quarters as we can (3)
- Give as many eleven-cent pieces as we can (1)
- Give as many nickels as we can (1)
- Give as many pennies as we can (3)

Seems ok.  But what if we were trying to give $0.33 back instead?
---
With our "normal" coin system we would give 1 quarter, 1 nickel, and 3 pennies for a total of 5 coins.

With the eleven-cent piece added, we could have done better.  We could have just given 3 eleven-cent pieces back.  A greedy algorithm would not have caught this.
---
In general, a problem needs to have **optimal substructure** if we want to be able to use a greedy algorithm to solve it.  Optimal substructure is a property of some problems that holds true if optimal solutions of subproblems of the original problem can be used to construct an optimal global solution to the overall problem.
---
Greedy solutions to problems are not always completely obvious though.  Consider the following problem:

We have a single processor and an operating system that cannot preempt tasks.  If we are given j1, j2, ..., jn tasks that run in t1, t2, ..., tn time, how can we schedule them to minimize the average completion time?
---
Notice we are talking about the average completion time here; how long each job must wait before it is completed, given they are given to the OS at the same time.

If we have:

| Job | Time |
|-----|------|
| j1  | 15   |
| j2  | 8    |
| j3  | 3    |
| j4  | 10   |
---
We could complete them in order:

![Possible schedule image](./greedy_algorithms/images/job_scheduling-1.png)

What is the average run time for each job?
---
The average completion time here is 25.

Can we do better?

Work on that with partners for a minute.
---
We can do better; if we decided to take the greedy approach of always completing the shortest job first, we would have this:

![Possible schedule image](./greedy_algorithms/images/job_scheduling-2.png)

What is the average run time now?
---
Now the average completion time is 17.75.  This works because this problem has optimal substructure.  To compute completion time for some job *i* we have to add how long it waited; *i-1* + *i-2* + ... + *i-(i-1)*.  By minimizing the wait time for each job we minimized the overall value.
---
Huffman Codes are another example of a greedy algorithm.  Huffman Codes are a type of compression.

Recall the ASCII character set?
---?image=./greedy_algorithms/images/ascii_table.png&size=auto
---
Of the 128 characters only about 100 of them can be printed (many are Ctrl characters).  Notice that the ceil(log 100) = 7 so we would need 7 bits to store every possible character.

In general we need ceil(log C) bits to encode any character set of size C.
---
However, do all characters appear with the same frequency in a file?  For instance, how often do we see words that have "q" or "z" in them?  How about "`" or "~"?

Probably not that often...
---
Let's assume we have a file that only includes the characters *a, e, i, s, t, space,* and* newline*.  We will assume they occur in the file as such:
---?image=./greedy_algorithms/images/huffman_1.png&size=auto auto
Hopefully you noticed the **Total** line; this file would require 174 bits of space on a disk, or use that much bandwidth in transfer.

Can we do better?
---
Huffman Codes can do better; on average about 25% better, but up to 50% or 60% on larger files are possible.

These codes do this by allowing the number of bits required to encode a character to vary.  If we represent the most common characters with the smallest possible encoding we save space.
---
Huffman Codes do this by representing each character in the character set in a tree.
---?image=./greedy_algorithms/images/huffman_2.png&size=auto auto
---
Notice how we determine the representation for a character; at each node if we traverse left we add a zero to the representation, if we go right we add a 1.

Before we start using this tree though, we need to make some optimizations.
---
We first may notice (or read in the book) that the newline character is the only leaf on that subtree.  Since that is the case we can just remove that subtree and put newline at the root:
---?image=./greedy_algorithms/images/huffman_3.png&size=auto auto
---
This means that the representation for newline is now ```11``` instead of ```110```.  If the character occurs 1000 times in the file we just saved 1000 bits.  Not bad!
---
This tree is what we call a **full tree*.  A full tree means that every node is either a leaf or has two children.
---
These properties ensure that even though the codes are different lengths that they are unambiguous.  This is a type of **prefix code**, which means that no representation of a character can be contained in the prefix of another character's representation.

An optimal prefix code will always be a full tree (though the inverse is not always true).
---
This tree might save us a bit of space, and allows us to have prefix codes.  But it isn't optimal.  What we need to do is be able to create a full binary tree that will give us a smaller total value for our number of bits.

This is exactly what Huffman codes do.
---
To compute a Huffman code we are going to create a **forest** of trees.  We will merge trees in this forest together in a greedy way until all trees are merged into one.
---
We determine which trees to merge by always selecting the trees with the smallest weight and merging those together:
---?image=./greedy_algorithms/images/huffman_4.png&size=auto auto
Continuing on:
---?image=./greedy_algorithms/images/huffman_5.png&size=auto auto
---?image=./greedy_algorithms/images/huffman_6.png&size=auto auto
---?image=./greedy_algorithms/images/huffman_7.png&size=auto auto
---?image=./greedy_algorithms/images/huffman_8.png&size=auto auto
Now we have a complete tree.  With this tree we have the following table of characters and the number of bits required to represent them:
---?image=./greedy_algorithms/images/huffman_9.png&size=auto auto
