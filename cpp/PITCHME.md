---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**The C++ Programming Language**
---
**History**
***

Is an extension to C.  If you don't know C, you may wish to practice here:

[C Programming Exercises and Info](http://www.learn-c.org/ "Learn to program in C")

C++ was created to add objects to C, as Object Oriented coding results in better program structure and organization.
---
**History**
***

Created by Bjarne Stroustrup ([Pronunciation](http://www.stroustrup.com/pronounciation.wav "Pronunciation of Bjarne Stroustrup")).

He worked with Simula during his Ph.D. time and wanted to bring some of those facilities to C.  He went to Bell Labs and created "C with Objects".  C++ came soon after.
---
**C++**
***

C++ is a compiled, statically typed language.  In some simple syntactic ways it is similar to Java, but that is really where the similarities end.

Whereas Java is compiled into an intermediate form called Java Bytecode that runs on the Java Virtual Machine (JVM), C++ compiles to object code that can be executed by a processor (though this is somewhat of a trivialization).
---
**C++**
***

Unlike Java, C++ is a multi-paradigm language.  While Java restricts us to an Object Oriented (OO) programming approach, C++ allows OO but does not require it.  This means we can write stand-alone functions that don't need to exist in the context of a class or object.
---
**C++**
***

Since we are coming from a Java background, let's look at a piece of Java code and compare it to C++.  Suppose we need to create a Car class to hold Car information.  It may look something like this:
---
```Java
/*
 * Java file.  MUST be named Car.Java
 */

public class Car {

  private String make;
  private String model;
  private int year;
  private double mileage;

  // Constructor
  public Car (String make, String model, int year, double mileage){
    this.make = make;
    this.model = model;
    this.year = year;
    this.mileage = mileage;
  }

  // Accessor
  public String getMake(){
    return this.make;
  }

  // Mutator
  public void setMake(String make){
    this.make = make;
  }

  private void internalFunction(){
    .... does something private ...
  }

  ... etc. ...
}
```
---
**C++**
***

In Java the "Syntactic Unit" (enclosure) for the class is the ```.java``` file.  In C++ we would likely have two files for this same class (*Important!* note that when we program generically this is likely not the case!).

By contrast, in C++ we would likely have a ```*.h``` file for the interface and a ```*.cpp``` file for the implementation.  The previous class might look something like this:
---
```C++
/*
 * Header (*.h) file.  Might be named
 * Car.h but doesn't have to be.  (Does need the *.h though!)
 */

// Must include string library; not built in!
#include <string>

class Car {

  public:
    // Constructor!
    Car(std::string make, std::string model, int year, double mileage);

    // Accessor
    std::string getMake();

    // Mutator
    void setMake(std::string make);

  private:

    std::string make;
    std::string model;
    int year;
    double mileage;

    void internalFunction();

    ... etc. ...
};
```
---
**C++**
***

Notice that the ```*.h``` file included *symbols* - function signatures and variable declarations.  It didn't really include any code.
---
**C++**
***

Code may change depending on the hardware we are running it on.  Even though C++ is portable it also has very low level capabilities.  This means it is not out of the ordinary for us to be working on a project that needs different, or perhaps optimized code that is different depending on the hardware.
---
**C++**
***

By separating our code into these two syntactic units, we can provide a common interface for the users, regardless of the type of hardware they are ultimately running on.
---
**C++**
***
This is really the crux of what an Abstract Data Type is - a piece of code we can use that doesn't require us to understand the underlying implementation.

Much like a floating point variable, we don't need to know how it is stored or manipulated behind the scenes; we just need to know how to use it.
---
**C++**
***

A ```*.cpp``` file is used for source code.  Our ```*.cpp``` file might look like this:
---
```C++
#include "Car.h"
#include <string>

Car::Car (std::string make, std::string model, int year, int mileage){
  this.make = make;
  this.model = model;
  this.year = year;
  this.mileage = mileage;
}

std::string Car::getMake(){
  return this.make;
}

void Car::setMake(std::string make){
  this.make = make;
}

void Car::internalFunction(){
  ...
}
```
---
**C++**
***

You may have noticed that both files contained the line:

```C++
#include <string>
```

We needed to include this statement in **both** files, because both files reference the symbols defined in it.
---
**C++**
***

C++ allows separately compilation of code.  This means that we can separate our code out into many files.  This is useful for organization and code reuse, but we must remember that every file is compiled separately and thus needs all the references it uses defined.
---
**C++**
***

You may also have noticed that our ```*.cpp``` file ```included``` the file ```Car.h```.  This is because our function signatures were declared in the ```*.h``` file.  Since any symbol we use needs to be declared before use, we needed to include the ```*.h``` file before we could define the rest of the code for our Car class.
---
**C++**
***

The ```::``` operator is new to many programmers.  This is the **namespace** operator.  Think of it as telling us where some symbol *lives*.  In the above code we are saying something like "the setMake(std::string make)" function "exists", or "lives" inside the Car namespace.
---
**C++**
***

Had we not prefaced our function definition names with ```Car::``` those functions would not have been included in the Car class; they would have just been global functions.
---
**C++**
***

Namespaces exist to help us keep our code separate and to avoid **namespace collisions**.  It is not uncommon for programmers to want to reuse common names in their code.  For instance, a programmer may want to use a function called ```max()``` to find the Car object with the largest odometer reading.  However, a math library may want to include a ```max()``` function to help in determining the largest of two integer or floating point numbers.
---
**C++**
***

To prevent these collisions we use the namespace operator.  Then, programmers could call the ```max()``` they know they want.

```C++
value = Car::max()
Or
value = Math::max()
```
---
**C++**
***

Some programmers are lazy though.  They don't want to type the extra keystrokes whenever they are using some specific namespace.  They might "know" (or suspect) that they are only ever going to be using a single namespace in their code.    Because of this you might see a line such as

```C++
using namespace std;
OR
using namespace Car;
```
---
**C++**
***

What this allows a programmer to do is to get by without typing the ```std::``` in front of every symbol that comes from the std namespace (or whichever other namespace(s) are referenced).

However, this is generally a BAD idea.
---
**C++**
***

In this class, we are **NEVER** going to use the ```using ...``` code.  Besides being lazy it allows namespace collisions to occur (which defeats the entire purpose of having namespaces), and it harms the readability of your code (which function does the programmer really wish to call?).
---
**C++**
***

As you progress in the Computer Science field you will hear some programmers tell you it is ok to do so, as long as you are careful.  While I disagree that is your decision.  However, there is one thing that you should never, ever do.
---
DON'T PUT A ""```using namespace...```"" statement in a ```*.h``` file.

**EVER.**

SERIOUSLY.  If they do it in their code, don't use their libraries, as they may not be safe.
---
**C++**
***

```*.h``` files are the files we include in our code to allow us access to another library.  By putting a ```using namespace``` line in a file that is included in someone else's code we pollute their namespace, resulting in unexpected behavior (at best) for the end user.  We can essentially break someone else's code through our laziness.

**DON'T** pollute the namespace.
---
**C++**
***

You will (likely) most often see people polluting the ```std::``` namespace.  This namespace is used for symbols that are in the C++ Standard Library.  These are collections of code that most programmers will need to make use of at one time or another, such as I/O, Data Structures, Common Functions, etc.
---
**C++**
***

For instance, the ```std::cout``` function from ```iostream``` can be used for output (to a screen or other output device).  You may use it like this:

```C++
// Notice I preface cout with the namespace!
std::cout << "Hello World!" << std::endl;
int x=42;
std::cout << x << std::endl;

etc.
```
---
**C++**
***

The ```<<``` operator is a stream operator.  What we are saying above is that we are passing some objects into an output stream (here the stream is cout.  Could be a file or other output stream).

We may handle input similarly:

```C++
std::cout << "Input a value: ";
int x;
std::cin >> x
```
---
**C++**
***

Though you should have noted that the stream operator is reversed.  Here we are passing what was coming from cin into x, whereas before we were passing some entity to cout.
---
**C++**
***

At this point, we can write a "Hello World" program.

This is a small program so we will put it all in one file.

Let's do so together.  **Code**
---
**C++**
***

[Source](https://github.com/irawoodring/263/blob/master/cpp/code_samples/hello_world_all_in_one.cpp "All in one hello_world code").
---
**C++**
***

Now, this is fine for a small project.  But for a project of any respectable size we need to separate our code into multiple "areas of concern".  Let's rewrite the previous code so that we have the following:

  - a library that has a hello world function.
    - it needs a ```hello_world.h``` and a ```hello_world.cpp```.
  - a main file that has a main function.  It should import and call our function.  It should know about the function because we include the ```hello_world.h``` file.

  **Code**
---
**C++**
***

[Source](https://github.com/irawoodring/263/blob/master/cpp/code_samples/hello_world.h "Separated files example of hello world.").
[Source](https://github.com/irawoodring/263/blob/master/cpp/code_samples/hello_world.cpp "Separated files example of hello world.").
[Source](https://github.com/irawoodring/263/blob/master/cpp/code_samples/hello_world_multi-file.cpp "Separated files example of hello world.").
---
**C++**
***

You may have noticed the compile command I used:

```
// Single file
clang++ hello_world.cpp

// Multiple files
clang++ hello_world.cpp main.cpp
```
---
**C++**
***

It is very important to understand that even though I passed multiple files to the compiler in the above line, that each file is compiled separately.

It is not the compiler's job to create an executable file.  The compiler creates executable code, but these must be combined together into an executable.  This is the linker's job.
---
**C++**
***

Had we wanted, we could have compiled each file separately and linked them together:

```
clang++ -c hello_world.cpp
clang++ -c main.cpp
clang++ -o program hello_world.o main.o
```
---
**C++**
***

This is what we have on most systems.  Pre-compiled libraries for the system exist (DLL's [dynamically linked libraries] on Windows, .so [shared object], dylibs or frameworks on OSX).

There is no need to recompile this common code each time a program wants to use it; we just need to link to it.
---
**C++**
***

Also important you should have noticed that I did NOT include a \*.h file on the compiler line.  \*.h files will be sourced in when they are #included.  We should not be passing them to the compiler manually.
---
**C++**
***

If you looked closely at our ```hello_world.h``` file you saw a few lines at the top that may be confusing:

```C++
#ifndef __H_HELLO_WORLD__
#define __H_HELLO_WORLD__

... Code ...

#endif
```
---
**C++**
***

These lines makeup an **include guard**.  Include guards make sure that code isn't pulled into a project more than once.  How could that happen?
---
**C++**
***

Imagine we need to print something to the screen, so we include the ```iostream``` library.  Perhaps we also include some other library code that gives us additional functionality, but this library also needs to print to the screen and also includes ```iostream```.  Include guards ensure that only one copy of ```iostream``` ends up in the final project.
---
**C++**
***

C++ has all the "normal" data types of C, such as

```char```, ```short```, ```int```, ```float```, ```long```, etc. as well as pointer and reference types.
---
**C++**
***

Just like C, C++ uses Pass-by-Value.  Also like C we can "simulate" Pass-by-Reference with pointers (yes, C++ has references too, we will see those in a moment!).
---
**C++**
***

Pointers in C++ work exactly the same way as they do in C.  For those of you who have never programmed in C before, a pointer is a variable that "points" to a memory address.
---
**C++**
***

A few things to know about pointers:

- they are a variable like any other
- they merely hold a memory address
- they can be confusing and dangerous, but are extremely powerful
---
**C++**
***

In a language like C that only allows pass by value, we can simulate pass by reference with a pointer:
---
```C
#include <iostream>

void modify(int* x){
  *x = *x * 2;
}

int main(int argc, char** argv){
  int x = 21;
  int* y = &x;  // y in a pointer to x
  modify(y);
  std::cout << x << std::endl;
}
```
---
**C++**
***

Output from this program should have been ```42```.

We were able to modify the value in the memory that y point to.
---
**C++**
***

Unlike C, C++ has reference types.  References are much safer than pointers.  Let's examine how C++ let's us use references:
---
```C++
// No references!
#include <iostream>

void changeMe(int x){
  x = 42;
  std::cout << "IN CHANGE ME! x = " << x << std::endl;

}

int main(int argc, char** argv){
  int x = 0;
  std::cout << "x = " << x << std::endl;
  changeMe(x);
  std::cout << "x = " << x << std::endl;

}
```
---
```C++
// With references!
#include <iostream>

void changeXa(int x){
  x = 42;
}

void changeXb(int &x){
  x = 42;
}

int main(int argc, char** argv){
  int x = 100;
  changeXa(x);
  std::cout << "x = " << x << std::endl;

  changeXb(x);
  std::cout << "x = " << x << std::endl;

}
```
---
**C++**
***

In the first example the value of x was passed to the function.  Any change to that value is local to the function - it does not affect the original variable.

With references though, the function can modify the original memory location.
---
**C++**
***

Anytime we use a reference, and we know that the function should not change the reference, we should declare the reference to be ```const```.  This provides safety and reliability.

```C++
int methodThatShoudlntModify(const int & x)
```
---
**C++**
***

Speaking of memory locations, it is essential for us to understand that there are two main areas in which our data is stored.  These two areas are called the **stack** and the **heap**.  They are used in very different ways.
---
**C++**
***

The stack is where executing code lives.  Every function that is called (including main) has a size that is computed by the compiler.  As a additional functions are called, they are given a stack frame on top of the previously called function:
---
<img src="./cpp/stack.png" width="250px" alt="Image of stack">
---
**C++**
***

The important thing to notice about the stack is that we cannot have dynamically sized data.  If FunctionOne needed to grow it could not do so or it could potentially overwrite any function's space above it.
---
**C++**
***

This creates an interesting dilemma.  What if we need to have a piece of data that grows or shrinks?  Perhaps an array, that might start with 10 elements but later needs to hold 20?

It can't go on the stack.  It must go somewhere else.
---
**C++**
***

You've probably guessed that the "somewhere else" is the heap.  The heap isn't nearly as structured as the stack; it can get very unruly.  If you are familiar with the concepts involved in disk defragmentation then you will probably understand the heap.
---
**C++**
***

There are two main uses for the heap.  We use it whenever

  - we need to keep track of dynamically sizable data
  - we wish to allow functions to operate on large pieces of information that is inefficient to pass around.
---
**C++**
***

While the heap is essential, it can be a bit complicated to use.  The stack is managed by the runtime system; all creation and release of memory is handled automatically.  When using the heap we need to manage the memory ourselves.
---
**C++**
***

When asking the system for heap space for dynamically sizable memory we need to specify two things - what type of data we wish to store and how much of it we need (note, we really don't *need* to tell it these things, we really just ask for a certain number of bytes.  But it is easier for us to think of it this way).
---
**C++**
***

For instance, let's pretend we need an array who's size may change in the future.

In C, we would use the malloc call to ask for heap memory.  In C++ we tend to use the ```new``` syntax:
---
```C++
// C method
int* myData = (int*) malloc(50 * sizeof(int));

// C++
int* myData = new int[50];
```
---
**C++**
***

Regardless of the call a pointer is returned.  This pointer holds the address of the first byte of memory allocated for us.

We **must** give this memory back when we are finished with it.  In C we used the ```free``` call.  In C++ we use ```delete``` or ```delete[]```.
---
**C++**
***

```C++
// C way
free(myData);

// C++ (Since this is an array we use delete[] and not delete)
delete[] myData;
```
---
**C++**
***

Now consider the following situation where we have a large object that we wish to operate on with other functions:
---
```
#include <iostream>

typedef struct Student {
        int id;
        float gpa;
        ... 1000 other fields ...

} Student;

Student newStudent(){
        Student a;
        a.id = 12345;
        a.gpa = 3.87;
        ... Set other fields ...
        return a;
}

int main(int argc, char** argv){
        Student a = newStudent();
        std::cout << a.id << std::endl;
}
```

Will this code work?
---
Yes, it will work (though it pains me to even type it out!  In general never pass an object, always use a pointer or reference).
---
**C++**
***

Even though it will work, it isn't efficient.  It would be far easier for us to pass a pointer to the object (or in C++ a reference!).
---
**C++**
***

At this point we should understand how to create basic imperative C++ programs.  It is now time to learn how to use objects with C++.
---
**C++**
***

We saw earlier how to define a class in C++.  But how do we instantiate one?  It turns out there are two ways.  If we have a Car object for instance:

```C++
Car a("Porsche", "911", "Yellow");

or

Car* a = new Car("Porsche", "911", "Yellow");
```
---
**C++**
***

The difference in these two methods of object creation is that when we create an object with the first syntax we don't have to manage the object's memory ourselves - it is automatically handled by the system.

If we use the second method we must give the object's memory back to the system via the ```delete``` command.
---
**C++**
***

The interesting thing about the one created with a pointer is that we need to use it differently than the other object, via a different syntax.
---
**C++**
***

Instead of the ```.``` syntax (i.e. ```a.color = "white";``` we must use the ```->``` syntax (i.e. ```a->color = "white"```.  Note that you can access the members that a pointer's object contains if you dereference it first, i.e. ```(*a).color = "white"``` but this isn't very readable.
---
**C++**
***

When might we need a pointer?  Consider the following code:
---
```C++
Car* newCar(std::string color){
  Car a;
  a.color = color;

  // This can't work!
  return &a;
}
```

Why would this fail?
---
**C++**
***

It fails because a copy of the pointer is returned, but what the pointer points to is gone.

Instead, we should do this:
---
```C++
Car* newCar(std::string color){
  Car* a = new Car(color);

  return a;
}
```

Why does this work?
---
**C++**
***

This works because ```Car a``` is created on the heap.  A pointer to it is returned to the calling function.

But remember! ANYTIME we use the ```new``` keyword we are entering into a contract to ultimately ```delete``` that object as well.  Don't forget to cleanup your memory!
---
**C++**
***

Being able to "be in charge" of memory ourselves is remarkably powerful, even though it can be dangerous to our code!  How do we remember to clean up our memory when we are finished with it?

If we are using classes this is (usually) rather easy.
---
**C++**
***

Besides the "Constructor", a C++ class also has a "Destructor".  Where the constructor "builds" the initial state of an object the destructor "tears it down".  This is usually an ideal place to release any members we asked for.
---
```C++
class DynamicList{
public:
  // Constructor
  DynamicList(){
    int* items = new int[50];
  }
  // Destructor
  ~DynamicList(){
    delete[] items;
  }
  ...
private:
  int* items;
  ...
};
```
---
**C++**
***

```~DynamicList()``` is the destructor for this class.  It will automatically be called by the system if the memory for it is managed, but if we create an object with the ```new``` keyword we need to call it manually.  We do this via the ```delete``` keyword.
---
```C++
DynamicList a;    // Will be cleaned up by the system.
DynamicList* b = new DynamicList();   // We must release!

delete b;       // How we release it.
```
---
**C++**
***

Note that we only have to create a destructor if our class is using memory that is unmanaged by the system.  Typically in C++ this occurs when you use the ```new``` keyword.
---
**C++**
***

The destructor isn't the only function we (sometimes) need to create when we are making C++ classes.  Since we are on the hook for dealing with any dynamic memory we create, we must make sure our object works as expected in all circumstances.
---
**C++**
***

In general, when dealing with dynamic memory, we need to keep in mind **The Big Five**.

- Destructor
- Copy Constructor
- Copy Operator=
- Move Constructor
- Move Operator=
---
**C++**
***

Each of these Big Five functions are provided to a class by default.  We only need to rewrite them if we are making use of dynamic memory or need some special functionality.
---
**C++**
***

The Copy Constructor is called whenever we pass an object to another object's constructor.  This should make an exact copy of an object:

```C++
Student a;      // Create a new object
Student b(a);   // Make an identical copy of a
```
---
**C++**
***

The problem here occurs when you copy an object that holds a pointer.  For instance, consider the following class (I'm going to put it all in the \*.h file for brevity):
---
```C++
class FriendList {
public:
  // Constructor
  FriendList(int numFriends){
    this.numFriends = numFriends;
    friends = new std::string[numFriends]
  }
  // Destructor
  ~FriendList(){
    delete[] friends;
  }

  // Code to add friends, etc.

private:
  std::string* friends;
  int numFriends;
};
```
---
**C++**
***

This class makes a dynamic array of friends, sized whatever the user passes in when the FriendList is created.  This dynamic list is pointed to by the pointer friends.

If we make an exact copy of this, then the new FriendList will have **exactly** the same friends.  If we make a change to one, it will change both.  Usually this is not what we want.
---
**C++**
***

This is what is called a **Shallow Copy**.  Usually we want to make a **Deep Copy**.
---
**C++**
***

The same thing occurs when we use the Copy Operator=.  Since C++ allows us to overload operators, we can define a custom meaning for what happens when we say this:

```C++
Student a;
Student b;
b = a;
```
---
**C++**
***

This can also result in a shallow copy, when the user probably wants a deep copy.

We can overcome this limitation by having the object create a new dynamic array (that we address with a pointer), and then copying the data over so there are two copies - one for each object.  Now changing one doesn't change them both.
---
**C++**
***

While we could have code that does this in two areas, the copy constructor and the copy operator=, in general we don't like repetitive code in Computer Science.  To get around this we use the **copy and swap** paradigm.
---
**C++**
***

This paradigm relies upon using a working copy constructor by the copy operator=.  This way, we only have one spot of "copy" code.  If we need to change or update it, it only needs to change in one place.
---
```C++
// Copy Constructor
FriendList(const FriendList& other){
  numFriends = other.numFriends;
  friends = new std::string[numFriends];
  // These will be copied since std::string has a
  // copy operator= defined.
  for(int i=0; i<numFriends; i++){
    friends[i] = other.friends[i];
  }
}

FriendList& operator=(FriendList other){
  // Notice!  other was passed by value.  This
  // means that the copy constructor was passed.
  // This is the copy we will use.

  // We are using std::swap to efficiently swap the memory
  // of these objects.  std::swap is optimized for many applications.
  std::swap(friends, other.friends);
  std::swap(numFriends, other.numFriends);

  // Return this object (or a reference to it).  other
  // will be consumed by garbage collection.  We have
  // implicitly made use of the copy constructor.
  return *this;
}
```
---
**C++**
***

Much like Java, C++ allows for generic programming.  A generic algorithm is one that operates the same regardless of data type it is operating on.  An ArrayList<> in Java is an example of a generic datatype; it doesn't matter what type of data it holds, it works the same.
---
**C++**
***

C++ provides capabilities for generic programming via **function templates** and **class templates**.
---
**C++**
***

The function template allows us to use a placeholder for any data type in our function.  For instance, we could do any of the following (not an exhaustive list):

```C++
template <typename T>
void doSomething(T t);

template <typename T>
T doSomething(T t);

template <typename T>
T* doSomething(T* t);
```
---
**C++**
***

Object templates work the same way, but we preface the class with the templating information:

```C++

template <typename T>
class MyClass {
public:
  T getOurData();
private:
  T ourData;
};
```
---
**C++**
***

We could then create an object of this particular type by **parameterizing** the object creation call:

```C++
MyClass<int> nums;
MyClass<std::string> strings;
```
---
**C++**
***

Etc.  We will code more comprehensive examples of these in class, and I will demonstrate how they work.
---
**C++**
***
