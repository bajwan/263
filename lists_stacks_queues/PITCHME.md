---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Lists, Stacks, and Queues**

(Chapter 3 in Weiss Text)
---
**You should be in class for this lecture (and all of them really...).  This one in particular will have a LOT of drawing on the board.**
---
First thing, remember that an Abstract Data Type (an ADT) is some grouping of other objects combined with a set of functions that can be performed on those objects.
---
For instance, in our AUDS data structure we created, the set of objects we held may have included our data and objects that held state information about the data such as the size (number of elements we were housing).
---
In this chapter we will be talking about the List ADT.  This is an ADT because we have no idea how the data is stored (that is hidden!).  It could be an array, a list, etc.

We only care that there are some functions that we can count on when we need to call them.
---
**Definitions**

- **a list:** a sequence of items of the form ```a0, a1, a2, ..., a(n-1)```.
- **empty list:** a list with size 0.
- **position:** the integer value corresponding to where an object is in a list.  In this lecture all lists are 0-indexed.
---
**Array Implementations**

We can easily create a fixed size list with an array.  This type of list has the advantage of extremely fast access times.  All we need to do to access some memory is calculate the offset from the start of the array.
---
This is what the indices operator usually does for us.

```C++
#include <iostream>

int main(int argc, char** argv){
        int a[1000];
        for(int i=0; i<1000; i++){
                a[i] = i;
        }

        std::cout << a[9] << std::endl;
        std::cout << *(a+9) << std::endl;
}
```
---
Thus it is extremely fast to access some area of memory for a lookup or a storage.  As a matter of fact, there is no faster access.

But arrays aren't perfect.
---
As you saw in the AUDS assignment, resizing arrays is slow, prone to programmer mistakes, and involves a LOT of copying since arrays are fixed size.

How long does it take to copy one array to another?
---
```C++
T arrayOne = new T[N];
... Fill it up ...
T arrayTwo = new T[N * 1.5];
for(int i=0; i<N; i++){
  arrayTwo[i] = arrayOne[i];
}
delete[] arrayOne;
arrayOne = arrayTwo;
```
---
From our Big-O lecture you should be able to calculate a time of O(N) for this copying.

What this implies is that if we are using our list in a way that causes us to add more data often, then the array may not be our best bet.
---
Additionally, what if we are trying to keep information in sorted order?  If we are using an array and data is coming in completely randomly what problem might we run into?
---
We would need to move elements "to the right" to insert any new elements into the list.  If the data is coming in a completely random way we will need to "shift right" N/2 times.
---
Also, if we deleted an element from anywhere other than the last element, and wished to remove any gaps we would need to "shift left" each time.
---
So it looks like insertions and deletions are not good for array.

To solve those issues Computer Scientists created the **linked list**.
---
**Linked Lists**

Linked lists are a series of nodes linked together into a list.  The nodes may be either singularly linked or doubly linked, meaning each node points to the just the next or the previous and the next.
---
Storing lists this way gives us a major benefit when it comes to adding and deleting in the midst of the list; we merely create a new node, break the link between the node that comes before it and the one that should come after it, insert it in and update the links.
---
How long does that take?

```C++
Node* newNode = new Node();

// Imagine we have a list with nodes
// one and two

newNode.nextNode = one.nextNode;
one.nextNode = newNode;
```
---
These are constant time operations; this is going to be O(1).  That is quick!

What about deletion?
---
Same thing.  Just update some pointers.  Once again this is an O(1) operation (this is if we already know where we are deleting from; if we have to find the data first we have an issue)!

So Linked Lists are excellent for when we are adding or removing data often.
---
What about a binary search operation though?

Which method of creating the list would work the best?

Why?
---
A binary search relies upon having a sorted list.  We start in the middle of the list and check if the element we are looking for is greater or less than the one we want.

We do that recursively until we find the element we are looking for.
---
If we are using a linked list, this could end up being very costly.  O(N) is possible.

However, if we have an array the time is O(log n).
