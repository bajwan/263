---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Sorting**

**Follows Weiss Chapter 7**
---
We are probably all familiar with sorting - ordering elements from smallest to largest (or largest to smallest).

While it is very easy for humans to sort things, it can be tricky to teach a computer to do so efficiently.
---
We are going to talk about several sorting algorithms in these sections, each of them will have a signature similar to the following:

```
void sortingMethod( vector<Comparable> & a);
```

Where ```a``` is an array (here a vector) that we want sorted in memory.
---
Be aware that the C++ STL (and most languages) provide optimized sorting implementations; in general you should be using those in your programming and not trying to roll your own or use the ones here (these are correct but not necessarily optimal).
---
Since C++ wishes to be able to use the same sorting methods for a variety of collections, the C++ function signatures will all take iterators, i.e.:

```C++
void sort(Iterator begin, Iterator end);
void sort(Iterator begin, Iterator end, Comparator cmp);
...
etc.
```
---
I believe that it is easier to learn when we are exposed to a topic in a variety of different ways.  To that end, we will be learning sorting through

- examining the algorithms
- manipulating physical and virtual objects
- listening to auditory implementations of how the algorithms work
- dance
---
Seriously, yes dance.  You're going to love it.
---
The first sorting algorithm we will learn about is Bubble Sort.

It isn't very good.  We will be studying it anyway though, to provide insight into some of the issues and possible optimizations available in sorting.
---
Bubble Sort might remind you of the percolating we did with priority queues.  The basic idea is that for each element in the array we are going to let it rise, bubble, percolate (whatever your favorite term is for it) to where it belongs.
---
An algorithm for Bubble Sort might look like the following:

```C++
template <typename Comparable>
void bubble_sort( std::vector<Comparable> & a){
        for(int i=0; i<a.size(); i++){
                for(int j=0; j<a.size(); j++){
                        if(a[i] < a[j]){
                                std::swap(a[i], a[j]);
                        }
                }
        }
}
```

What is the Big-O of this algorithm?
---
Hopefully you noticed that the run-time is O(n^2).  Even as O(n^2) algorithms go though, this one is bad.  Regardless of what happens it will always run O(n^2) times.  We *could* make it slightly better by checking after each iteration of j to see if something changed.  It nothing changed we can be done.
---
