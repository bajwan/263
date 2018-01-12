# Setting Up Your Environment

As mentioned in class, I strongly urge you to use the EOS system for your homework.  Additionally, for this class, it is unlikely that you should need an IDE.  We will mostly be working from the command-line.

This assignment will help you get an environment setup for completing the work in this class.

## Choosing an Editor

If you are logging into EOS via a graphical method (i.e. x2Go), there are quite a few graphical editors to choose from.  The EOS system has gedit, gvim, and others installed.  Additionally, you can always install an editor such as Atom or Sublime in your account.

However, it may be easier (and will certainly be faster once you get the hang of it) to learn a command-line editor.  ```vim``` is probably the most popular, as it is nearly ubiquitous on \*nix systems (OSX, BSD, Linux, etc.).  There are others though, such as Emacs, nano, ne, etc.  I use ```vim``` fairly religiously so I that will be what I demonstrate in class.  You are, however, free to choose your own.

Regardless of what you choose, for the purposes of this assignment I would like you to play with ```vim``` by going through the vim tutorial here:

[http://www.openvim.com/](http://www.openvim.com/ "Online vim tutorial")

If you choose not to use it, that is up to you.  But you need to adopt some editor for the rest of this assignment.

## Downloading the CIS263_Project_Template

As noted in class I provide a project template for all of our homework in this class.  This template aids in learning how to separate out our files, and provides a handy compilation script called a ```Makefile```.  To download the project template, use the following command:

```
git clone https://github.com/irawoodring/CIS263_Project_Template.git HW1
```

Where HW1 is the name you wish to call the downloaded folder.

Once it is cloned, we will create a very simple program that asks a user for the radius of a circle and returns the area and perimeter of a circle with that radius.  We are going to keep all of our code in a single file since this is such a trivial project and we do not plan to reuse the code.

```
cd HW1
vim src/hw1.cpp
```

Enter your code (feel free to look at our notes online and your book).  When you believe the project is correct, type hit the <ESC> key and typed

```
:wq
```

This stands for "write and quit" for ```vim```.  If you are using a different editor it is up to you to learn the appropriate save and exit commands.

Now, type

```
make
```

at the command line.  If you are in the HW1 (or whatever you called it) folder, the compiler will be invoked and it will attempt to compile your code.

You will likely have some errors or warnings at this point - that is normal.  It is rare that we enter a program correctly the first time (in fact when I don't get errors I often worry...).  Edit the file to correct any mistakes and try again.  Do this until your program compiles.

When your program compiles, you should have an ```a.out``` link in the folder.  This is a link to the executable file contained in the ```bin``` folder.  You can run that program by typing

```
./a.out
```

Verify that your program works correctly.

Once your program is complete, cd to the directory that **contains** HW1.  Enter the following command:

```
tar cvf YOUR_NAME-hw1.tgz HW1/*
```

Notice, if you named your folder something other than HW1 you will need to change that here.

This command compresses the files and folders in your project into a single file.  Upload this file to Blackboard as your submission.

## Thoughts...

This may be the first time many of us have used the command-line.  I understand it may be unfamiliar, but it is necessary and will help you become a better Computer Scientist.  Put in the time now so you don't have problems with it later.

Don't provide the code to anyone, but feel free to answer questions on Slack (and to ask them!).  We are learning as a community.  Slack is a wonderful tool to allow us to share ideas and help one another.

## Submission

Turn this in on Blackboard by Wednesday, January 17th at 8:00 a.m.
