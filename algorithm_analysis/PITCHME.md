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
