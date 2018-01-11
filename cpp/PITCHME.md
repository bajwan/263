---
CIS 343 - Structure of Programming Languages

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
**Overview**
***

C++ is a compiled, statically typed language.  In some simple syntactic ways it is similar to Java, but that is really where the similarities end.

Whereas Java is compiled into an intermediate form called Java Bytecode that runs on the Java Virtual Machine (JVM), C++ compiles to object code that can be executed by a processor (though this is somewhat of a trivialization).
---
**Overview**
***

Unlike Java, C++ is a multi-paradigm language.  While Java restricts us to an Object Oriented (OO) programming approach, C++ allows OO but does not require it.  This means we can write stand-alone functions that don't need to exist in the context of a class or object.
---
**Overview**
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
**Overview**
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
**Overview**
***

Notice that the ```*.h``` file included *symbols* - function signatures and variable declarations.  It didn't really include any code.
---
**Overview**
***

Code may change depending on the hardware we are running it on.  Even though C++ is portable it also has very low level capabilities.  This means it is not out of the ordinary for us to be working on a project that needs different, or perhaps optimized code that is different depending on the hardware.
---
**Overview**
***

By separating our code into these two syntactic units, we can provide a common interface for the users, regardless of the type of hardware they are ultimately running on.
---
**Overview**
***
This is really the crux of what an Abstract Data Type is - a piece of code we can use that doesn't require us to understand the underlying implementation.

Much like a floating point variable, we don't need to know how it is stored or manipulated behind the scenes; we just need to know how to use it.
---
**Overview**
***

A ```*.cpp``` file is used for source code.  Our ```*.cpp``` file might look like this:
---
```C++
#include "Car.h"
#include <string>

Car::Car (){
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
**Overview**
***

You may have noticed that both files contained the line:

```C++
#include <string>
```

We needed to include this statement in **both** files, because both files reference the symbols defined in it.
---
**Overview**
***

C++ allows separately compilation of code.  This means that we can separate our code out into many files.  This is useful for organization and code reuse, but we must remember that every file is compiled separately and thus needs all the references it uses defined.
---
**Overview**
***

You may also have noticed that our ```*.cpp``` file ```included``` the file ```Car.h```.  This is because our function signatures were declared in the ```*.h``` file.  Since any symbol we use needs to be declared before use, we needed to include the ```*.h``` file before we could define the rest of the code for our Car class.
---
**Overview**
***

The ```::``` operator is new to many programmers.  This is the **namespace** operator.  Think of it as telling us where some symbol *lives*.  In the above code we are saying something like "the setMake(std::string make)" function "exists", or "lives" inside the Car namespace.
---
**Overview**
***

Had we not prefaced our function definition names with ```Car::``` those functions would not have been included in the Car class; they would have just been global functions.
---
**Overview**
***

Namespaces exist to help us keep our code separate and to avoid **namespace collisions**.  It is not uncommon for programmers to want to reuse common names in their code.  For instance, a programmer may want to use a function called ```max()``` to find the Car object with the largest odometer reading.  However, a math library may want to include a ```max()``` function to help in determining the largest of two integer or floating point numbers.
---
**Overview**
***

To prevent these collisions we use the namespace operator.  Then, programmers could call the ```max()``` they know they want.

```C++
value = Car::max()
Or
value = Math::max()
```
---
**Overview**
***

Some programmers are lazy though.  They don't want to type the extra keystrokes whenever they are using some specific namespace.  They might "know" (or suspect) that they are only ever going to be using a single namespace in their code.    Because of this you might see a line such as

```C++
using namespace std;
OR
using namespace Car;
```
---
**Overview**
***

What this allows a programmer to do is to get by without typing the ```std::``` in front of every symbol that comes from the std namespace (or whichever other namespace(s) are referenced).

However, this is generally a BAD idea.
---
**Overview**
***

In this class, we are **NEVER** going to use the ```using ...``` code.  Besides being lazy it allows namespace collisions to occur (which defeats the entire purpose of having namespaces), and it harms the readability of your code (which function does the programmer really wish to call?).
---
**Overview**
***

As you progress in the Computer Science field you will hear some programmers tell you it is ok to do so, as long as you are careful.  While I disagree that is your decision.  However, there is one thing that you should never, ever do.
---
DON'T PUT A ""```using namespace...```"" statement in a ```*.h``` file.

**EVER.**

SERIOUSLY.  If they do it in their code, don't use their libraries, as they may not be safe.
---
**Overview**
***

```*.h``` files are the files we include in our code to allow us access to another library.  By putting a ```using namespace``` line in a file that is included in someone else's code we pollute their namespace, resulting in unexpected behavior (at best) for the end user.  We can essentially break someone else's code through our laziness.

**DON'T** pollute the namespace.
---
**Overview**
***

You will (likely) most often see people polluting the ```std::``` namespace.  This namespace is used for symbols that are in the C++ Standard Library.  These are collections of code that most programmers will need to make use of at one time or another, such as I/O, Data Structures, Common Functions, etc.
---
**Overview**
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
**Overview**
***

The ```<<``` operator is a stream operator.  What we are saying above is that we are passing some objects into an output stream (here the stream is cout.  Could be a file or other output stream).

We may handle input similarly:

```C++
std::cout << "Input a value: ";
int x;
std::cin >> x
```
---
**Overview**
***

Though you should have noted that the stream operator is reversed.  Here we are passing what was coming from cin into x, whereas before we were passing some entity to cout.
---
**Overview**
***

At this point, we can write a "Hello World" program.

This is a small program so we will put it all in one file.

Let's do so together.
---
**Overview**
***

[Source](https://github.com/irawoodring/263/blob/master/cpp/code_samples/hello_world_all_in_one.cpp "All in one hello_world code").
