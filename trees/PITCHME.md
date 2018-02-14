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
**Trees** can be viewed as a collection of nodes, where one node serves as a **root**.  From this root there are 0 or more nonempty subtrees, each that connect to the root.
---?image=./trees/images/trees.png
---
At the "bottom" of the tree are nodes with no children; these nodes are known as **leaves**.

Any node that has the same parent node as another node is a **sibling** node to that node.  All the "normal" familial relationships are there; nodes can have aunts, nephews, grandparents, etc.
---
A **path** from one node to another node is a sequence of nodes from n[1]to n[k] such that n[i] is the parent of n[i+1].

The **length** of a path is the number of edges on the path.
---
We measure between nodes in multiple ways; the length of a path from the root to n[i] is the **depth**.  The root has a depth of 0.

The **height** of some node n[i] is the length of the longest path from n[i] to a leaf.  Leaves have a height of 0.  A tree's height is the height of its root.
---
We say that a node n[1] is an ancestor of a node if there is a path from n[1] to n[2].  We would then say that n[2] is a descendant.

If n[1] and n[2] are not the same node we say we have a **proper ancestor** and **proper descendant**.
---
We can implement a simple tree (note we are NOT talking about binary trees at this point) as follows:

- Create a TreeNode class
  - holds our data
  - holds a pointer to our firstChild
  - holds a pointer to our nextSibling

- We get to our children and siblings through links (we've basically created two linked lists).
---?image=./trees/images/possible_tree.png?size=auto
---
In code this might look like this (from our book):

```C++
struct TreeNode {
  Object data;
  TreeNode* firstChild;
  TreeNode* nextSibling;
};
```
