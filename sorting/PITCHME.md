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
Hopefully you noticed that the run-time is O(n^2).  Even as O(n^2) algorithms go though, this one is bad.  Regardless of what happens it will always run O(n^2) times.  We *could* make it slightly better by checking after each iteration of ```j``` to see if something changed.  If nothing changed then we can be done.
---
Visually, the algorithm looks (and sounds!) something like this (notice that this demo is the more optimized Bubble Sort version):

[Play sound-of-sorting demo]
---
Let's practice it!

[Cards](https://deck-of-cards.js.org/)
---
Or, if you learn better via dance:

https://www.youtube.com/watch?v=lyZQPjUT5B4
---
Wow, that is a long video.  We need a faster sorting algorithm.

Let's consider Insertion Sort.
---
The idea of Insertion Sort is that we will move one element each iteration and insert it into the array where it needs to go.  After each iteration ```p``` we know that 0-```p``` elements are in sorted order.
---
One implementation (from our book) of this algorithm is as follows:

```C++
template <typename Comparable>
void insertion_sort( std::vector<Comparable> & a ){
        for( int p = 1; p < a.size( ); ++p ){
                Comparable tmp = std::move( a[ p ] );
                int j;
                for( j = p; j > 0 && tmp < a[ j - 1 ]; --j ){
                        a[ j ] = std::move( a[ j - 1 ] );
                }
                a[ j ] = std::move( tmp );
        }
}
```
---
A visual/auditory example:

[Play sound-of-sorting demo]
---
And let's not forget the AlgoRythmics!

https://www.youtube.com/watch?v=ROalU379l3U
---
Now, let's practice.

[Cards](https://deck-of-cards.js.org/)
---
Once again, this algorithm is not particularly fast.  In fact, it still runs in O(n^2) time.  However, the O(n^2) time for Insertion Sort is much better than the O(n^2) time for Bubble Sort, since Insertion Sort is able to stop when it discovers the correct spot to place the element, and Bubble Sort must finish the iteration.
---
It might seem weird to think that the two have the same run time, yet one is faster.  We may need to remind ourselves that Big-O is about rate of growth - not about speed.  Both of these algorithms have the same rate of growth, even though one is faster.
---
For those of you interested, the Computer Scientist Jon L. Bentley at Bell Labs showed you could write an insertion sort in 3 lines:

```C
void iisort(int *a, int n)
{
  int i, j;
  for (i = 1; i < n; i++)
    for (j = i; j > 0 && a[j-1] > a[j]; j--)
      iswap(j, j-1, a);
}
```
---
If you like, you can read his paper here:

http://cs.fit.edu/~pkc/classes/writing/samples/bentley93engineering.pdf
---
What this three line version shows is just how simple Insertion Sort can be.  Due to the simplicity and lack of overhead, for small collections and small sub-collections it is often still used.

In fact, some heavy duty sorting functions often resort to Insertion Sort to optimize sorting of smaller lists.
---
Selection Sort is the third sorting algorithm we will discuss.

Selection Sort works by searching the collection for the next largest element at each iteration, and then moving that element to the current spot.
---
```C++
template <typename Comparable>
void selection_sort( std::vector<Comparable> & a){
        for( int i=0; i<a.size()-1; i++){
                for(int j=i+1; j<a.size(); j++){
                        int min_index = i;
                        if(a[j] < a[min_index]){
                                min_index = j;
                        }
                        std::swap(a[min_index], a[i]);
                }
        }
}
```

Big-O anyone?
---
You guessed it; once again we have an O(n^2) algorithm (we're going to get better, just wait!).

Selection Sort is considered slower than Insertion Sort though.  Can you see why?
---
For the same reason that Insertion Sort is faster than Bubble Sort, it is faster than Selection Sort.  Selection Sort must always finish the iteration it is on; Insertion Sort stops the current iteration when it finds the correct spot.
---
Here is our demo:

[Play sound-of-sorting demo]
---
We can't forget our dance:

https://www.youtube.com/watch?v=Ns4TPTC8whw
---
And let's practice!

[Cards](https://deck-of-cards.js.org/)
---
