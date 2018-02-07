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

        // These next two are equivalent
        std::cout << a[9] << std::endl;
        std::cout << *(a+9) << std::endl;
}
```
---
Thus it is extremely fast to access some area of memory for a lookup or a storage.  It is O(1), and there is no faster access.

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
We would need to move elements "to the right" to insert any new elements into the list.

What is the worst possibility in this case?
---
We could have completely reversed data coming in.  Then we would need to perform the array shift operation O(N) times (with an average of N/2 shifts each time).
---
Also, if we deleted an element from anywhere other than the last element, and wished to remove any gaps we would need to "shift left" each time.

This could also result in needing to re-shift the array O(N) times (with N/2 shifts each time), if we needed to get the first element each time.
---
So it seems if we are doing a lot of insertions and deletions arrays aren't the thing to use.

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
---
C++ has something called the Standard Template Library (STL).

The STL provides both of these implementations.  The array based data structure is the ```vector<>``` class.

The list is the ```list<>``` class.

We choose the one that suits our needs the best, based on how we are going to use our data.
---
Both of these data **containers** or **collections** provide some similar methods.  For instance,

```
int size() const;
void clear();
bool empty() const;
void push_back(const Object & x);
void pop_back();
const Object & back() const;
const Object & front() const;
```
---
The list also provides

```
void push_front(const Object & x);
void pop_front();
```
---
Vector also gives us

```
Object & operator[] (int idx);
Object & at(int idx);
int capacity();
void reserve(int newCapacity);
```
---
So now we see something interesting...

We gain access to these two types of lists in different ways.  Vector provides us with index operators, list does not.

It would be nice if we had a way to gain access to the data in a uniform way...
---?image=./lists_stacks_queues/images/enter_the_dragon.jpg?size=80% auto
---?image=./lists_stacks_queues/images/eti.png?size=80% auto
---
Not all collections have the same interfaces - for good reasons.  We use collections in different ways, to solve different problems.

For instance, consider the Map container from the C++ STL.
---
Map<> stores key,value pairs.  For instance, we might hold

```C++
std::map<int, Citizen> citizens;
citizens['198339485'] = citizenOne;
citizens['983773282'] = citizenTwo;
```

If we wanted to index some Citizen objects by Social Security Number.
---
But what if we wanted to have generic, re-usable code that can operate on any kind of collection?  For instance, what if we wanted to search through all the elements and find the max one?

In this particular instance we are going to pretend that the Citizen class has an overloaded operator> and some comparison has been defined by the programmer (maybe we are looking for the oldest Citizen).
---
The way we are used to doing something like that is this:

```C++
Citizen largest = citizens[0];  // Uh-oh...
for(int i=0; i<citizens.size; i++){
  if(citizens[i] > largest){    // Not going
    largest = citizens[i];      // to work...
  }
}
```

Why won't this work?
---
Indices operators for maps don't work that way...

We can't ask for the i-th element.

We need something that is collection agnostic.  C++ provides iterators.
---
An iterator provides position information in a collection.  Iterators must be typed the same as the data they point to:

```C++
vector<int> nums;
vector<int>::iterator nums_it;

map<int, Citizen> citizens;
map<int, Citizen>::iterator citizens_it = citizens.begin();
```
---
Since C++11 we have the auto keyword that automatically determines data type information for us:

```C++
vector<int> nums;
auto citizens_it = citizens.begin();
```
---
To get an iterator, we ask for one that points to either the beginning or ending of a collection:

```C++
auto citizens_it = citizens.begin();
auto nums_it = nums.end();
```

These give us the first and last elements, respectively.
---
Once we have an iterator we can use the increment and decrement operators to move forward and backward through a collection:

```C++
nums_it--;    //Goes back one position
citizens_it++;  //Goes forward one position
```
---
Iterators are references to objects stored at certain locations.  If we want to access the object at that position we do so with the ```*``` operator:

```C++
int age = *(citizens_it).age;
```
---
Iterators may be compared to see if they point to the same location.  So if we have multiple iterators we could ask:

```C++
if(nums_it == nums_it2){
  ... Do something ...
}
```
---
Now that we know what an iterator is, how can we use one to solve the aforementioned problem?  How can we find the largest object?
---
```C++
Citizen largest = *(citizens).begin();
for(auto citizens_it = citizens.begin(); citizens_it != citizens.end(); ++citizens_it){
  if(*(citizens_it) > largest){
    largest = *(citizens_it);
  }
}
```
---
