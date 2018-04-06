---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Dynamic Programming**

(Chapter 10 in Weiss)
---
We have seen before that recursive algorithms can be quite eloquent.  They are a natural solution for many problems, but for others can be quite inefficient.
---
You've probably seen this classic example:

```C
long long fib( int n){
  if( n<= 1 ){
    return 1;
  } else {
    return fib( n - 1 ) + fib( n - 2 );
  }
}
```
---
If we were to calculate the runtime for this algorithm we would see that it is exponential; that is much too slow for any input of significant size.

If we looked at a trace of the algorithm at work, we notice there is much repeated work:
---?image=./dynamic_programming/images/fib.png&size=50% auto
---
A better solution might be:
---
```C
long long fibonacci( int n ){
  if( n<=1 ){
    return 1;
  }

  long long last = 1;
  long long nextToLast = 1;
  long long answer = 1;

  for( int i = 2; i<n; ++i ){
    answer = last + nextToLast;
    nextToLast = last;
    last = answer;
  }

  return answer;
}
```

What is the runtime here?
---
Here is another possible solution:

```C
long long fib( int n ){
  long long fib[n+2];
  int i;

  fib[0] = 0;
  fib[1] = 1;

  for(int i=1; i<=n; ++i){
    fib[i] = fib[i-1] + fib[i-2];
  }

  return fib[n];
}
```
---
What do both of these iterative algorithms do differently from the recursive version?
---
Both of these algorithms store values in a table for use later.  This is the hallmark of dynamic programming; instead of relying upon recomputing a value later, we store it.
---
This works whenever we can combine solutions to subproblems to solve the overall problem.  In the Fibonacci algorithms the answer to fib(n) = fib(n-1) + fib(n-2); we needed the subproblems solved before we could solve the overall problem.
---
This means (just like our greedy algorithms) that we are dealing with problems that exhibit optimal substructure.
---
One of the classic Computer Science example problems of dynamic programming is the Longest Common Subsequence (LCS) problem.

A subsequence in two strings is a group of characters that appear in the same order in both strings but don't have to appear next to one another (this isn't the longest substring problem).
---
We see this type of problem in bioinformatics quite often; we may need to find the common subsequences of nucleotides in two pieces of DNA or RNA.

For instance, we might have the two strings:

X="ACGTACG"
Y="AGGGAAT"
---
It may not be obvious, but this problem has optimal substructure. Let us create a table:

| | 0 | A | C | G | T | A | C | G |
|-|---|---|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|A| 0 |   |   |   |   |   |   |   |
|G| 0 |   |   |   |   |   |   |   |
|G| 0 |   |   |   |   |   |   |   |
|G| 0 |   |   |   |   |   |   |   |
|A| 0 |   |   |   |   |   |   |   |
|A| 0 |   |   |   |   |   |   |   |
|T| 0 |   |   |   |   |   |   |   |
---
We now fill the table from left-to-right, top-to-bottom.  This equates to us comparing substrings.  We have two possible cases:

- for element i,j in our LCS table, if X[i] is equal to Y[j], LCS[i,j] = LCS[i-1,j-1] + 1. This means that the last character in our substrings match.
- if X[i] is not equal to Y[j], LCS[i,j] = maximum of C[i,j-1] or C[i-1, j].  This means that our last characters don't match and we should find the previous maximum matching length.
---
Using these rules, complete the table.
---
| | 0 | A | C | G | T | A | C | G |
|-|---|---|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|A| 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
|G| 0 | 1 | 1 | 2 | 2 | 2 | 2 | 2 |
|G| 0 | 1 | 1 | 2 | 2 | 2 | 2 | 3 |
|G| 0 | 1 | 1 | 2 | 2 | 2 | 2 | 3 |
|A| 0 | 1 | 1 | 2 | 2 | 3 | 3 | 3 |
|A| 0 | 1 | 1 | 2 | 2 | 3 | 3 | 3 |
|T| 0 | 1 | 1 | 2 | 3 | 3 | 3 | 3 |
---
To find our subsequence from this table we have to traceback through it.  Starting at the bottom right, if the current value is greater than the value above or to the left of it, then it was a match.  Choose it and go up-left.

Else, we just follow the current number either up or left.
---
In our table, we should have been able to find multiple LCS; AGA, AGG and AGT are three of them.
---
We previously looked at the Fractional Knapsack problem.  We saw that problem could be solved with a greedy approach, but that the 0/1 Knapsack problem - the problem of filling a knapsack to its max value with whole items - could not be solved in a greedy way.

Dynamic Programming works well in this case though!
---
But first, let's consider the direct approach.

Let's assume we have a knapsack that holds 5.  We want to fill it with the following items so we have the maximum value.

|Item | Weight | Value |
|----:|-------:|------:|
|   1 |    1  |   75  |
|   2 |    4  |   43  |
|   3 |    2  |   37  |
|   4 |    3  |   90  |
---
We could just compute all the possible permutations of items and choose the one with the highest value.

This could take a while though, if the number of items was big enough...
---
We could choose the following:

{} {1}, {2}, {3}, {4}
{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}
{1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}
{1,2,3,4}

There are 16 choices...
It turns out that this problem is exponential (2^n).  We have 4 items, 2^4=16.
---
There must be a better way.

If we think about this problem for a few minutes, we might notice that it can be solved recursively...
---
Let's assume we have a function V(I,W) that calculates the maximum value we could obtain by choosing up to I items if we had a weight of W.  It would need to work like this:
---
For all values of i and w, choose the maximum of these possibilities:
- We don't take this item.  Choose the best value possible from taking i-1 items and this W instead.
- We do choose this item.  Our bag only holds a weight of W, so we subtract our current item's weight from W and find the maximum value we can get if we had a bag that only held W - current item's weight.
---
Note that these are the only two things that can happen.  Taking this item either gives us a better solution or it doesn't.  If it doesn't, we ignore it.
---
We are going to apply a dynamic programming approach to solving this problem.  We will first model our choices in a table, with rows corresponding to number of items and columns to weight:
---
| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 |
|1| 0 |   |   |   |   |   |
|2| 0 |   |   |   |   |   |
|3| 0 |   |   |   |   |   |
|4| 0 |   |   |   |   |   |
---
To calculate our values, we will fill the table from left to right, top to bottom.  First, we calculate V(1,1) - meaning we determine what the maximum value for a single item is, if our maximum weight is 1.
---
| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 |
|1| 0 | 75|   |   |   |   |
|2| 0 |   |   |   |   |   |
|3| 0 |   |   |   |   |   |
|4| 0 |   |   |   |   |   |
---
What is the best we could do if we could only choose from the first item with a weight limit of 2?
---
| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 |
|1| 0 | 75| 75|   |   |   |
|2| 0 |   |   |   |   |   |
|3| 0 |   |   |   |   |   |
|4| 0 |   |   |   |   |   |

Still 75.
---
| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 |
|1| 0 |75 |75 |75 |75 |75 |
|2| 0 |75 |75 |75 |75 |   |
|3| 0 |   |   |   |   |   |
|4| 0 |   |   |   |   |   |

Now we get interesting though; V(2,5) needs to determine the max value we can attain from the first two items if we have a weight limit of 5.
---
So we need to compute the max of taking the item or not taking the item.

If we don't take the item we choose from the row above us; this means we take the previous best value from the choices presented when we had i-1 items at this weight.
---
If we do take this item, it is going to take up weight[i] in our backpack.  So we perform a subtraction of W - weight[i]; this leaves the amount of room in our backpack we have to work with.  Maximize this value by looking up in the table V(i-1,W - weight[i]).
---
Completing the table we get

| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
|0| 0 | 0 | 0 | 0 | 0 | 0 |
|1| 0 |75 |75 |75 |75 |75 |
|2| 0 |75 |75 |75 |75 |118 |
|3| 0 |75 |75 |112 |112 |118 |
|4| 0 |75 |75 |112 |165 |165 |
---
The final dynamic programming problem we will study is the All-Pairs Shortest Path problem.  This is another classic problem of Computer Science.  The solution we will be looking at is the one published by Floyd.
---
