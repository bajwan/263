---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Hashing (Follows Chapter 5 in Weiss book)**
---
While we were discussing arrays we learned that arrays provide incredibly fast access times - O(1) in fact - because we can quickly calculate the address offset and jump directly to a memory address.  However, arrays require us to index via a number.  Sometimes, this is not what we want.
---
Trees allow us to index in any way we want, but finding a particular element is an O(log N) operation (at best).

So, is there a way we can combine the best of both of these structures?  Can we index with something other than a number and still look up our data in O(1) time?
---
We can!  We can use a **hash table**.  Now, by gaining these two features we lose some others; hash tables don't order information.  We can't ask for a findMin and findMax or print the list in sorted order in linear time.
---
Some other names you may have heard for hash tables are associative arrays and maps.
---
The main idea of a hash table is using a fixed size array to hold information, but converting some representation of the information held into an index for the array.

We use a **hash function** to calculate the index.
---?image=./hashing/images/hash_table&size=50% auto
---
In the picture of the hash table we see that john is placed in index 3, phil in 4, etc.  It is the job of the hash function to determine where each object will go.
---
Our hashing function must choose an index between 0 and tableSize - 1 for the object we wish to insert.  We need this calculation to be as fast as possible - but we also need to make sure that every object goes in a different cell.  Additionally, our objects should be well distributed (not bunched up in certain areas!).

This makes hashing a somewhat complicated business.
---
Let us consider a very simple situation.  Let's say we have

- keys for our objects are integers
- table size is 10
- a hashing function of hash(int x){ return x % 10; }
---
In this situation things are easy; If our object's key is 4 our hashing function returns 4.  If it is 9 the hashing function returns 9.

No issues at all!

Unfortunately things are not usually so simple.
---
What if our keys were 20, 30, and 70?  Our hashing function would return:

- 0 for 20
- 0 for 30
- 0 for 70

These are called **collisions**; we have multiple objects that the hash assigns to the same spot.

That isn't going to work...
---
This illustrates a point about hashing functions: we must pick them very carefully based upon our keys.
---
An additional note is that we usually pick a table size that is a prime number.  The reason behind this is that collisions are more likely when numbers have common factors.  Choosing a prime number ensures there are very few factors.
---
Let's consider another situation.  Typically keys are based on strings; for instance we might have a list of students and hash them by their last names, or a list of colors and hash them by their name.

Suppose we have the following:
---
- a key is a string of 8 or fewer characters
- our table size is 10,007
- our hash function adds the ASCII values and mods them by the table size
---
```C++
int hash( const string & key, int tableSize ){
  int hashVal = 0;

  for(char ch:key){
    hashVal += ch;
  }

  return hashVal % tableSize;
}
```
---
This function is simple and quick.  Unfortunately it doesn't distribute keys very well.  Consider, what if we have the keys:

- HANK
- TIE
- JAW
---
All of these ASCII words sum to 34 and would then be placed in the same spot.

Let's think about the math behind this for a minute.  Our ASCII values go from 0 to 127, and we have 8 possible characters per string.

This means that even though our table size is 10,007 that we will only use 127 * 8 = 1,016 of those spots.
---
Let's try a different hashing function now (table size will stay the same and inputs will stay the same).

- This function will assume that there are at least 3 characters per string.
- It will sum the first character of the string with 27*the second and 729 * the third
---
```C++
int hash2( const std::string & key, int tableSize ){
        return ( key[ 0 ] +
                 27 * key[ 1 ] +
                729 * key[ 2 ]
               ) % tableSize;
}
```
---
Since we are using the first three characters there are 26^3 possible combinations here.  That is 26^3 = 17,576 possible combinations.

That seems great!  Are there any problems here?
---
The problem here lies with a property of our data.  English words don't have that many different 3 character beginnings.  With this hashing functions

- THROW
- THREE
- THROMBUS
- THREATEN
- THROTTLE

And any other "THR" word will all be placed in the same spot.
---
So not only do we have to worry about distribution from our hashing function but we also need to be very aware of the properties of the data we want to store.
---
Let's take a look at one more hashing function.  This one will

- Make use of every character in the string
- Will multiply every character by 37 and sum it with the others.
- Allows numbers to get rather large so makes use of unsigned ints (there are no negative indices so why use an int).
---
```C++
unsigned int hash3( const std::string & key, int tableSize ){
        unsigned int hashVal = 0;

        for( char ch:key ){
                hashVal = 37 * hashVal + ch;
        }

        return hashVal % tableSize;
}
```
---
This function is pretty good (according to the book it doesn't have the best distribution but is ok) but should result in few collisions.  It is also very fast.
---
So we must be careful when creating hashing functions.  We must be aware of our data properties, our table size, the distribution of the hashing function, and the speed of the function.

Unfortunately it turns out that (except in special cases) there are no perfect hashing functions.  So we have to deal with collisions eventually.
---
So how do we deal with these collisions?

It turns out there are several methods that are commonly used.  The first one we are going to look at is called **separate chaining**.
---
Separate chaining is the idea of creating a vector (or some other similar structure) to store elements that hash to the same spot.

When we are looking up an element, we first hash its key and then iterate over the added chain until we find the element we desire.
---?image=./hashing/images/separate_chaining.jpeg&size=50% auto
Often it is the case that the most recent data requested is the most recent data added, so in general it is a good idea to place the new element at the front of the chain.

This implies we should use a data structure like a linked list and not an array (why?).
---
If you remember our earlier lectures on arrays you should remember that placing an element at the front of an array causes all of the other elements to shift right - which is very slow.
---
Ultimately though, we chose a hash because we want fast searching based on a key.  Preferably we want O(1) lookups; if we are using separate chaining this may not be possible.

What is the worst possible situation that could happen with separate chaining?
---
The worst case scenario occurs if all of our keys hash to the same spot, and the element we are looking for is at the end of the chain.  In this case, what is the runtime?
---
It is an O(n) operation to go through the entire list; if our hashing function was an O(1) operation then the minimum possible runtime in this scenario is as bad as a regular array (and much worse than a tree...).
---
So, we need some methods of chaining that don't involve using separate lists.

The first of these methods is something we call **linear probing**.
---
To hash via linear probing we first calculate our hash and navigate to that index.  If the index is full, we go to the next available spot.

What problems might we have with this method?
---
You probably realized fairly quickly that this can be slow.  What you might not have realized is that besides the slow speed we start to see something called **primary clustering** begin to happen.
---
Primary clustering refers to the situation where we have blocks of clustered elements in the array.

Given the elements {89, 18, 49, 58, 69} for instance, we could run into a situation like this:
---?image=./hashing/images/linear_probing.jpeg&size=50% auto
---
Notice the clustering that occurred between 8-2 (with wraparound).

The rest of the table remained empty; we didn't do a good job of distributing our data.
---
**Quadratic probing** is another method of handling collisions.  Where linear probing sequentially proceeds until an empty spot is found in the array, quadratic probing uses a quadratic function.  For instance, f(i) = i^2.
---
It works like this; we hash the key and navigate to that array index.  If the index is full we check the next spot.  If that one is full we navigate to 4 spots past (the initial index).  If that spot is full, we navigate to 9 spots past, etc.
---
It turns out that if we are using quadratic probing and the table size is prime that we can guarantee to find a spot this way if the table is always half empty (Theorem 5.1 in the book).
---
Can you see any issues with quadratic hashing?
---
It turns out that when we are using quadratic hashing elements with keys that cause collisions also will attempt to fill the same subsequent cells (since they are using the same collision function).

This is called **secondary clustering**.
---
What we need is function that makes a decision about how to resolve a collision based upon the properties of the the current data.

One way we do this is by **double hashing**.
---
Double hashing works like this:  we calculate an index from the key.  We find the current index is full so hash again and go that distance past the original index.  As long as we choose a good hash function this should help distribute our data fairly well!
---
