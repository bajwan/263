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
Those are all of the O(n^2) algorithms we will be discussing in depth.  From here on we will be discussing more efficient algorithms.
---
But first, we need to talk about the concept of **inversions**.  An inversion is an ordered pair *(i,j)* in a collection such that *i<j* but *a[i] > a[j]*.

For instance, given the example from the book of the list ```34,8,64,51,32,21``` we have 9 inversions:

- (34, 8), (34, 32), (34,21), (64, 51), (64, 32), (64, 21), (51, 32), (51, 21), and (32, 21)
---
We view a sorted array as an array that doesn't have any inversions.  Swapping two elements that are out of place in an array gets rid of one inversion.

So if we must go through *n* elements in a list and perform *i* inversions, we would end up with a runtime of O(n+i).
---
Let's consider Insertion Sort.

In a worst-case scenario we would have an array in reverse order.  Then we would have *(n(n-1))/2* inversions in the list.  We must check each element which takes O(n) time, so our runtime is O(n + (n(n-1))/2) or O(n^2).
---
Let's also consider what could happen if the list is already in sorted order.

Then we must go through *n* elements in our list.  We have 0 inversions in our list, so our run time is O(n+0) = O(n).  This means that to sort an already sorted list with insertion sort gives us O(n), or linear time.
---
It turns out that most simple sorting algorithms perform a single inversion at a time.  We want faster algorithms.

This means we need to remove more than one inversion each time.
---
Shellsort is the first algorithm that runs in less than O(n^2) - quadratic - time.

Shellsort is a **diminishing increment sort**.  It uses some sequence *h1, h2, ..., ht*.  The sequence is not important as long as *h1=1*.  The algorithm then works as follows:
---
- For each *hk* from *ht* to *h1* we will sort all elements *hk* indices from one another using an insertion sort.  This is called a phase.
- When a phase completes we are *hk-sorted*.
- Once we finish an *hk* sort, the *hk-1* sort doesn't undo any work from the early phases.
---?image=./sorting/images/shellsort.png&size=50% auto
---
It is probably pretty obvious to you that different increments result in different runtimes for this type of sort.  Oddly enough, the increments Shell himself put forth (it was created by a programmer names Donald Shell) are very bad.
---
Shell suggested the sequence *ht=floor(n/2)* and *hk=floor(h[k+1]/2)*.  This sequence results in a quadratic algorithm in the worst case.

Another sequence, called the Hibbard sequence, gives us an O(n^[3/2]) time.

The Hibbard sequence is ```1,3,7,...,2^k-1```.
---
We are not going to go through proofs of these runtimes in class.  They are quite complicated.  If you are interested you can look them up in the book.

The code looks something like this though:
---
```C++
template <typename Comparable>
void shell_sort( std::vector<Comparable> & a ){
        for( int gap = a.size( ) / 2; gap > 0; gap /= 2 ){
                for( int i = gap; i < a.size( ); ++i ){
                        Comparable tmp = std::move( a[ i ] );
                        int j=i;

                        for(;j>=gap&&tmp<a[j-gap];j-=gap){
                                a[ j ] = std::move( a[ j - gap ] );
                        }

                        a[ j ] = std::move( tmp );
                }
        }
}
```

Notice this is using the poorly chosen increments that Shell suggested.
---
This one might be a bit confusing to some of you.  No worries, AlgoRythmics to the rescue!

https://www.youtube.com/watch?v=CmPA7zE8mx0
---
Sound of Sorting demo
---
And then we should practice a bit ourselves:

[Cards](https://deck-of-cards.js.org/)
---
We will go through Heapsort fairly quickly, since we discussed the concepts of a heap in depth while learning about Priority Queues.  Heapsort works by building a heap, which is an O(n) operation, and then performing n ```deleteMin()``` operations which take O(log n) each.
---
Our natural inclination is to create a new array to store the sorted elements as we delete them from the heap.  It turns out we don't need to do this.  Each call to ```deleteMin()``` is going to reduce the size of the heap by one; we can store the element removed in that spot.
---
Unfortunately that will result in a reverse-sorted list.  We can avoid this by using a max heap with a ```deleteMax()``` function instead of a min heap.
---?image=./sorting/images/heapsort-1.png&size=50% auto
---?image=./sorting/images/heapsort-2.png&size=50% auto
---
Let's practice a bit.

[Cards](https://deck-of-cards.js.org/)
---
And even though this algorithm looks a bit different then some of our others (since we are visualizing a tree), the AlgoRythmics dance this algo for us as well:

https://www.youtube.com/watch?v=Xw2D9aJRBY4
---
Next we will discuss Mergesort.  This is one of our most optimal sorting algorithms, and the first recursive sorting algorithm we will discuss.
---
Mergesort works by continuously splitting a list, then merging the lists together in order.

This sounds a little vague; let's look at the code:
---
This function is just an entry point or "driver" function:

```C++
template <typename Comparable>
void mergeSort( std::vector<Comparable> & a ){
        std::vector<Comparable> tmpArray( a.size( ));
        mergeSort( a, tmpArray, 0, a.size( ) - 1);
}
```
---
This function splits the list into a left and right list:

```C++
template <typename Comparable>
void mergeSort( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray, int left, int right ){
        if(left < right){
                int center = (left + right) / 2;
                mergeSort( a, tmpArray, left, center );
                mergeSort( a, tmpArray, center+1, right );
                merge( a, tmpArray, left, center + 1, right );
        }
}
```
---
This function merges the lists back together in order:

```C++
template <typename Comparable>
void merge( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd ){
        int leftEnd = rightPos - 1;
        int tmpPos = leftPos;
        int numElements = rightEnd - leftPos + 1;

        while( leftPos <= leftEnd && rightPos <= rightEnd ){
                if( a[ leftPos ] <= a[ rightPos ] ){
                        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
                } else {
                        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
                }
        }

        while( leftPos <= leftEnd ){
                tmpArray[tmpPos++] = std::move(a[ leftPos++ ]);
        }

        while( rightPos <= rightEnd ){
                tmpArray[tmpPos++] = std::move(a[ rightPos++ ] );
        }

        for(int i=0;i < numElements; ++i, --rightEnd ){
                a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
        }
}
```
---
Sound of Sorting demo to get a feel for this in action.
---
AlgoRythmics!

https://www.youtube.com/watch?v=XaqR3G_NVoo
---
This one requires a bit of practice as well:

[Cards](https://deck-of-cards.js.org/)
---
Mergesort is pretty great, though better in some languages than others due to how memory is handled, comparisons are made, objects are passed around, etc.

Mergesort does require extra work space though, so this can be an issue.
---
Quicksort has, for many years, been the sorting algorithm of choice for generic sorting tasks.  It doesn't require the extra memory that Mergesort does, and it has a Big-O of O(n log n).
---
The basic idea behind Quicksort is that we pick some element in the list, then create two sets - the items in the list smaller than the chosen element, and those that are bigger.  We then recursively call the Quicksort function on the sublists.
---
We will have a driver (or entry) function since we will be calling the main algorithm recursively:

```C++
template <typename Comparable>
void quicksort( std::vector<Comparable> & a ){
        quicksort( a, 0, a.size( ) - 1 );
}
```
---
And a method to find our pivot point:

```C++
template <typename Comparable>
const Comparable & median3( std::vector<Comparable> & a, int left, int right ){
        int center = (left + right) / 2;
        if(a[center] < a[left] ){
                std::swap( a[left], a[center] );
        }
        if(a[right] < a[left] ) {
                std::swap( a[left], a[right]);
        }
        if(a[right] < a[center]){
                std::swap(a[center], a[right]);
        }

        std::swap(a[center], a[right - 1]);
        return a[right - 1];
}
```
---
And finally our core sorting code:

```C++
void quicksort( std::vector<Comparable> & a, int left, int right){
        if(left + 10 <= right){
                const Comparable & pivot = median3(a, left, right);

                int i = left, j = right - 1;
                for(;;){
                        while(a[++i] < pivot){}
                        while(pivot<a[--j]){}
                        if(i<j){
                                std::swap(a[i], a[j]);
                        } else {
                                break;
                        }
                }

                std::swap(a[i], a[right - 1]);

                quicksort(a, left, i-1);
                quicksort(a, i+1, right);
        } else {
                insertion_sort(a, left, right);
        }
}
```
---
One more time for the AlgoRythmics!

https://www.youtube.com/watch?v=ywWBy6J5gz8
---
And let's listen to the Sound of Sorting...
---
And practice!

https://deck-of-cards.js.org/
---
Here's the thing with quicksort.  Picking the pivot is really, really important.

A fairly natural inclination for some programmers is to use the first element in the list as the pivot.
---
Picking the first element might work ok if the data is in a perfectly random order.  But, what happens if it is not?  For instance, what could happen if the list is already sorted?
---
If we have this list:

10, 9, 8, 7, 6, 5, 4, 3, 2, 1

And we pick the first element as the pivot, we end up with the two sets:

S1 = 9, 8, 7, 6, 5, 4, 3, 2, 1
S2 =
Pivot = 10
---
Well this isn't good...

Since we are recursively calling our function on the two sets the same thing continues to happen.  This results in an O(n^2) algorithm.
---
The best (safest at least) way to pick a pivot is to pick it randomly.  Unfortunately, random number generators can be a bit slow.  Still, if you've got the time do it.
---
Our book details a different strategy though, called the median-of-three.  It relies upon the fact that an ideal pivot point would be the median of the list (this would result in two equally sized sublists).

It would be too slow to figure out the median each time though.
---
Instead, we can estimate the median.  We can do this by choosing the left-most element, the right-most element, and the center element and choosing the median of those.  It has been shown that this strategy gives pretty good results (and requires very little overhead).
---
You probably also noticed that when the sublists got less than a size of 20 (10 per sublist) that the algorithm calls insertion sort.  This is an optimization that can help a good deal, since insertion sort requires much less overhead than quicksort.
---
Since the list is continuously split into sublists in Quicksort, it turns out we get less than 20 elements that need to be sorted quite frequently.  This explains why experiments have shown that using this method speeds up our sorting by about 15%.
---
To this point we've seen some O(n^2) algorithms, an O(n^(3/2)) algorithm, and a few O(n log n) algorithms.  It turns out that for general purpose sorting we can't do better than O(n log n).  However, if we know some things about our data we can do better in specific scenarios.
---
For instance, there are a few linear - O(n) - sorting algorithms.  They only work in very special cases though.  The first of these is called **Counting Sort**.
---
Counting Sort works when we know the entire range of our data.  We create an array that holds each possible value in the range, and store the number of times each of the elements occurred in the original list.  We then do some math to determine the final indices for the values.
---
Say we have this list:

{9, 3, 4, 5, 8, 6, 1, 2, 4 }

We can see that we have 8 elements ranging from 1-9, so we will create an array goes up to index 9.  Then we count the number of times each element occurred:
---
{9, 3, 4, 5, 8, 6, 1, 2, 4 }

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
|   | 1 | 1 | 1 | 2 | 1 | 1 | 0 | 1 | 1 |
---
Now we do some math.  For each index *k* the value of array[k] = array[k] + array[k-1]:

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
|   | 1 | 1 | 1 | 2 | 1 | 1 | 0 | 1 | 1 |
|   | 1 | 2 | 3 | 5 | 6 | 7 | 7 | 8 | 9 |
---
For each number *i* in the list we look at array[i].  The value at array[i] is the index for where to put this value from the list.  Put the element in that spot and decrement the count by 1.
---
{9, 3, 4, 5, 8, 6, 1, 2, 4 }

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
|   | 1 | 2 | 3 | 5 | 6 | 7 | 7 | 8 | 9̶ 8 |

Sorted array:

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |   | 9 |
---
Continuing the process we get:

{9, 3, 4, 5, 8, 6, 1, 2, 4 }

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
|   | 1 | 2 | 3 | 4 | 4 | 5 | 6 | 8 | 9 |
---
Another O(n) algorithm is **Bucket Sort**.  Bucket Sort requires that we have the following properties for our data:

- we have a fairly evenly distributed range of data
- we know the range of the data
- we can divide the range up into N equal parts
- we can easily tell which part any element is in
---
Suppose we have the following values in a list:

{ 86, 44, 55, 32, 97, 83, 20, 3, 39, 25 }

We have 10 numbers so we'll create 10 "bins".  In our example instead of dividing the the bins up we will just assume they are linked lists.
---
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
|   | 3 | 20 | 32 | 44 | 55 | | | 83 | 97 |
|   |   | 25 | 39 |    |    | | | 86 |   |
---
Now we simply go through the array and print the ordered sublists from each bucket.

{3, 20, 25, 32, 39, 44, 55, 83, 86, 97 }
---
The final O(n) algorithm we will see is the **Radix Sort**.

For Radix Sort we need

- the lengths of all the keys to be the same; we'll say the length is *k*
- each element in *k* must be between some min and max value
---
The algorithm works in phases; at each phase it sorts via the "digits" of *k*, going from least significant to most significant.  The following image illustrates on integers:
---?image=./sorting/images/radix.png&size=auto
---
Of interest is that we can sort strings this way as well, if they are the same length (or if we pad them to be).  This works since each character in the string has as underlying value that is within a fixed range.
