---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Trees**

(Chapter 4 in Weiss Text)
---
We have been looking at sequential data structures so far;  we saw that an array has ideal access times (even for elements in the middle!), and linked lists allow for fast insertions and deletions.
---
For a large amount of data though, that is changing rapidly, we need a better option.

Many of our "better options" are based on the idea of trees.
---
*Trees* can be viewed as a collection of nodes, where one node serves as a *root*.  From this root there are 0 or more nonempty subtrees, each that connect to the root.
---?image=./trees/images/trees.png?size=auto
