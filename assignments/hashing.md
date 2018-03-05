### Hashing

We went over hash maps and hashing this past week.  C++ (most languages actually) provides maps in its standard library so there is little reason to ever create our own.  However, the ability to understand how they work and are written is important.

For this project you are tasked with creating a hashmap class.  It can be generic if you like (probably easier to write it that way), or you can write it specifically to house objects of type ```Superhero```.  A ```Superhero``` has the following fields:

```C++
int page_id;
std::string name;
std::string urlslug;
std::string id;
std::string alignment;
char eye_color;
char hair_color;
char sex;
std::string gsm;
boolean alive;
int appearances;
std::string first_appearance;
int year;
```

As per object oriented best practices all fields should be private.

Your hashmap class should hash based on the entire name of the superhero.  You will use the separate chaining method to handle collisions (each array indice will correspond to a vector<Superhero> object where the data will be stored).  Your hashmap will provide only the following public methods:

```C++
boolean insert(const Superhero & s);
Superhero & get(const std::string name);
```

The insert function returns either true or false depending on whether a collision occurred on insert.  Regardless of whether a collision occurred or not the object should be inserted in the vector.  Additionally, as we discussed in class, the object should be added to the front of the vector.

## Hashing Functions

You need to create three different hashing methods.  You may look in your book, online, in journals, etc. to come up with the three hashes, just be sure you document where you found each.

I want us to see how different hashing functions might affect collisions.  To that end, I want you to read in the superhero.csv database file attached below.  You should split each line and create a ```Superhero``` object with it, store it, and keep track of whether a collision occurred.  You should provide a text file in your repository called "RESULTS.md".  This file should contain a copy of your hash function text and the number of collisions that occurred during the course of inserting all superheroes into the hashmap.

## Necessary Files

You should have a ```main.cpp``` file in your ```src``` directory that runs your main code of loading the file, creating an instance of a hashmap, creating objects, and keeping track of the number of collisions.  Your program need do nothing more than print out the number of collisions when complete.

You should have a ```my_hash.h``` file that includes all of your hashmap code.  This file should go in the ```include``` directory.

You should have a ```superhero.h``` in the ```include``` directory that provides the interface for the ```Superhero``` class, and a ```superhero.cpp``` file in ```src``` that provides the implementation.

## Notes

- You may work with a partner (and probably should).
- Don't go crazy with the hash functions.  Just remember that it must mod based on the table size.
- Start early, and contact me for clarifications.  Also make use of our Slack channel.

## Submission

Turn in a .zip of all your code and files, or a Github link of all files by 8:00 a.m. Wednesday, March 21st.
