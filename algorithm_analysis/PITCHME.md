---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Algorithmic Analysis**
---
Consider the following code:

```C++
#ifndef                 __H_BUBBLE_SORT
#define                 __H_BUBBLE_SORT

#include <iostream>

template <typename T>
void bubble_sort(T* arr, size_t size){
        for(int i=0; i<size; i++){
                for(int j=i+1; j<size; j++){
                        if(arr[i] > arr[j]){
                                T temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
}

template <typename T>
void printArray(T* arr, size_t size){
        for(int i=0; i<size; i++){
                std::cout << arr[i] << "\t";
        }
        std::cout << std::endl;
}

#endif
```
---
**Algorithmic Analysis**

How long does it take this code to run?
---
**Algorithmic Analysis**

Actually, what does that question mean?

Let's see how it runs on a few different machines.  EOS first:
---
**Algorithmic Analysis**

Now my demo machine:
---
**Algorithmic Analysis**

So, one is slightly faster.  Does that tell us anything?

Not really.  Running an algorithm on two different machines basically just highlights a difference in the machines.  Doesn't tell us much about the algorithm.
---
**Algorithmic Analysis**

Computer Scientists realized this and came up with platform agnostic ways to help compare algorithms.  The primary tools we are going to be using to analyze algorithms are

- Big O (Big O)
- Big Ω (Big Omega)
- Big Θ (Big Theta)
---
**Algorithmic Analysis**

Big O is defined as

f(x) = O(g(x)) if and only if there exists constants *c* and *k* such that 0≤f(n)≤cg(n) for all n≥k.

What does this mean?
---
**Algorithmic Analysis**

It means that as the input size to f(n) grows, there comes a point at which some cg(n) will always be bigger than f(n).  It means we have an upper bound.
---
**Algorithmic Analysis**

To find these upper bounds we typically take the highest order term of the equation.  We can do this safely because the higher order term contributes vastly more to the equation than the rest of the terms.
---
**Algorithmic Analysis**

To see why this is, consider the equation x^2+10x+3.  We will plot the individual pieces.

https://www.desmos.com/calculator
---
**Algorithmic Analysis**

We can readily see that the 10x starts out bigger than x^2 for lower values of x.  However, as x approaches infinity the growth of x^2 is drastically more than 10x.
---
**Algorithmic Analysis**

Let's take a small value of x and see what we get.  For instance, let's use 5.

At x=5 x^2=25, but 10x=50.  So f(x)=75.

But at a larger value, for instance 10000:

x=100,000 x^2=10,000,000,000 and 10x=100,000.  f(n) = 10,000,100,000.
---
**Algorithmic Analysis**

Really the 100,000 is negligible here.  It just doesn't add that much to the overall total.  For the purposes of analyzing algorithms we usually just drop this part.
---
**Algorithmic Analysis**

Notice that we can now say that x^2+10x is Big-O of x^2.  Why?  Well, due to the definition of Big-O we can pick some arbitrary c such as 3.  We will use g(n)=x^2.  We notice that at some point there is an n (here around 30) for which ALL values of 3x^2 are greater than all corresponding values of x^2 + 10x.

https://www.desmos.com/calculator
---
**Algorithmic Analysis**

This seems weird... does that mean that just x is also Big-O of x^2?

It turns out, yes it does.  This isn't a very precise bound, but it does fit the definition.  Usually we try to find a more precise bound.
---
**Algorithmic Analysis**

Keep in mind - saying an algorithm has a smaller Big-O value does not mean that algorithm will run faster in every case.  It just means that as the size of the input to the two algorithms grows, at some point one becomes permanently faster than the other.
---
**Algorithmic Analysis**

But how do we determine the functional runtime of some algorithm?

- We look at every line in the algorithm
- We assign a value based upon how many times that line runs, in terms of the input size
- We sum the values together.  This will result in a polynomial.
- The largest order term will be the Big-O value.
---
**Algorithmic Analysis**

Consider our Bubble Sort code:
```C++
void bubble_sort(T* arr, size_t size){
        for(int i=0; i<size; i++){                  // n
                for(int j=i+1; j<size; j++){        // n * n
                        if(arr[i] > arr[j]){        // n * n * 1
                                T temp = arr[i];    // n * n * 1
                                arr[i] = arr[j];    // n * n * 1
                                arr[j] = temp;      // n * n * 1
                        }
                }
        }
}
```

So sum to 5n^2+n as the runtime, or O(n^2).
---
**Algorithmic Analysis**

Let's compare that with this one:

```C++
// Insertion sort.  Modified from
// https://www.geeksforgeeks.org/insertion-sort/

void insertionSort(T* arr, int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       // What is the most number of times
       // this will run?  We are concerned
       // with the WORST case.
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
```
---
**Algorithmic Analysis**

Once again we get a Big-O of O(n^2).  I thought Insertion Sort was better than Bubble Sort, what gives? (We will discuss this when we get to sorting.  For now, just theorize about it)..
