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

We can do better though; if we decided to take the greedy approach of always completing the shortest job first, we would have this:

![Possible schedule image](./greedy_algorithms/images/job_scheduling-2.png)

What is the average run time now?
---
