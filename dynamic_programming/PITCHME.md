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
What do both of these algorithms do differently from the recursive version?
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
|=|===|===|===|===|===|===|===|===|
|0| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|A| 0 |   |   |   |   |   |   |   |
|G| 0 |   |   |   |   |   |   |   |
|G| 0 |   |   |   |   |   |   |   |
|G| 0 |   |   |   |   |   |   |   |
|A| 0 |   |   |   |   |   |   |   |
|A| 0 |   |   |   |   |   |   |   |
|T| 0 |   |   |   |   |   |   |   |
---
