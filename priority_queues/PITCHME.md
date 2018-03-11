---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Priority Queues**

**Follows Sebesta Chapter 6**
---
We previously talked about the idea of a queue - a first-in-first-out (FIFO) data structure.

We saw that queues can be made from a list (possibly with the use of an adapter class), and that they are useful for a variety of situations.
---
One of the situations we talked about was a printer queue, where a user generally expects that their job is processed in the order in which it arrived; this is a common use case (and appeals to our desire for fairness!).  Sometimes though, we wish to give some other job a higher priority.
---
Consider an operating system for instance.  It makes little sense for all jobs in an OS to have equal priority; certain jobs are simply more important than others.  I/O for instance - if we are simply writing something to disk that we don't anticipate needing for awhile there is no real hurry.
---
In a situation like this we need some new data structure that allows us to assign priority to data.  The ADT we will be discussing here is called a **priority queue**.
---
It is important to note that we can have a minimum priority queue or a maximum priority queue, meaning we sometimes we consider the smallest weight the most important and sometimes the largest.  In these notes (and the book) we will generally be talking about minimum priority queues unless specifically stated otherwise.
---
This ADT supports two operations (as always different implementations may call them different things but the ideas are the same):

```C
insert(const T & data);
const T & deleteMin();
```
---
Notice that the insert function didn't require any special parameter to provide weight or priority information.  Some implementations do so, but for our ADT model we are assuming that the objects can be compared via some operator or comparison function.
---
In C++ for instance, the class signature is as follows:

```C++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

Where Compare is some comparison object.  The default is std::less is equivalent to operator<.
---
Notice that the Container in C++ defaults to a ```std::vector```.  Let's consider the possible ways we could store a priority queue behind the scenes.
---
**Linked List Approach**

If we wish, we could store the data in a linked list.  How might this affect our runtimes?
---
We must provide the two functions listed above, ```insert``` and ```deleteMin```.  Let's imagine we do the following:

- insert at the front of the linked list - an O(1) operation
- traverse through the entire list to find the min for deleteMin - an O(N) operation

Or:
---
We could keep our list in sorted order.  This implies the following:

- insertions would then become O(N) operations
- deleteMins would be O(1)
---
But, it turns out that there is generally a better option which relies on an array-based approach (which is probably why the C++ implementation uses a std::vector by default).
---
The implementation we will be discussing relies upon the fact that we can store a binary tree in an array.  We tend to do this when we need a very simple representation of a tree and don't want the full overhead of a more complete tree object.
---
An array-based implementation of a binary tree is easy because we can quickly calculate the location of children and parents of nodes due to the following properties for any array element *i*:

- the left child can be found in index 2*i*.
- the right child can be found in index 2*i* + 1.
- The parent is in index floor(*i*/2).
---?image=./priority_queues/images/priority_queue.png&size=50% auto
---
