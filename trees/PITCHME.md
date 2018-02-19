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
---?image=./trees/images/trees.png&size=50% auto
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
---?image=./trees/images/possible_tree.png&size=50% auto
---
In code this might look like this (from our book):

```C++
struct TreeNode {
  Object data;
  TreeNode* firstChild;
  TreeNode* nextSibling;
};
```
---
**Binary Trees** are trees with special properties.  A binary tree enforces the rule that a node never has more than 2 children.

Note there is no rule for a generic binary tree that we keep the tree balanced.

This means we can (in a worst case scenario) end up with a tree that devolves into a linked list.
---
One thing we might do with a generic binary tree is evaluate expressions.  An **expression tree** puts an operator at each root node and operands at the leaves:
---?image=./trees/images/expression_tree.png&size=50% auto
---
To evaluate this expression tree we would then recursively evaluate the left and right subtrees.
---
When we have a large amount of data and we are concerned with searching we often use the **Binary Search Tree** ADT (BST).

A BST is a binary tree with a very important additional property; every left child is smaller than its parent and every right child is larger than its parent.

Here we have a binary search tree and a binary tree:
---?image=./trees/images/binary_tree_and_bst.png&size=50% auto
---
Note that the second tree cannot be a BST because 7 is greater than 6 but is located on the left subtree of 6.
---
So the most important property of the BST assumes that our data can be ordered; we need to have data that is comparable.

In C++ this likely means we will want to be using data that has the ```operator<``` overridden.
---
Our book has an excellent example of a BST.  You can look at it here:

(Though please be aware that he includes the "using namespace std" in this file ONLY to make it easier for students to read.  This should **NEVER** happen in production code, and he notes that in the book).

[BST](https://github.com/irawoodring/263/tree/master/trees/code_samples/BinarySearchTree.h "BST code from Weiss book")
---
Spend a few minutes looking at this code.  In particular look at the ```findMin()``` and ```findMax()``` functions.  Describe in English what they are doing.
---
Hopefully you can see that the minimum value in a BST is the leftmost leaf, and the maximum value is the rightmost leaf.
---
A note...

I particularly like this piece of code.  So much so in fact, that I would be shocked if it didn't end up on some assessment in the future...

You should probably ask a lot of questions about it.
---
It is not uncommon for us to wish to completely traverse a tree.  Perhaps we want to evaluate an expression tree we saw earlier, perhaps for some other reason.  Regardless, there are multiple ways to go about tree traversal.
---
**Preorder traversal** occurs when a node is evaluated before its children.
**Inorder traversal** occurs when we evaluate the left child, ourselves, and then the right child.
**Postorder traversal** occurs when we evaluate the left and right children first, then the current node.
---
**In-class work on Weiss BST code, and creating traversal algorithms.**
---
Inserting an element in a BST is easy without any real caveats (the only real issue is do we store duplicates.  We can, but is usually better to just keep a counter variable of the number "in" that node).
---
Deletions are more complex (this tends to be true for a lot of data structures, according to Weiss).

If we are deleting a leaf node then the operation is easy.  If a node to delete has once child, no problem.  But what do we do if the node has two children?
---
The normal strategy is to remove the node and replace it with the smallest node in the right subtree (which will be a leaf).  This can result in a tree that is deeper on the left than the right, since this algorithm "steals" nodes from the right subtree to fill the left.
---
If we don't expect to have very many deletions we sometimes merely mark an element as deleted and leave it in the tree.  This is called **lazy deletion**.  This
---
Binary Search Trees are not perfect.  It is easy for a BST to become unbalanced:
---?image=./trees/images/unbalanced_bst.png&size=50% auto
---
The previous tree is very unbalanced (possibly from too many deletions).

As a BST becomes more and more unbalanced, the search behavior can devolve into an O(N) operation (basically the tree becomes a linked list).

We need to prevent this from happening.
---
**AVL Trees** are a self-adjusting (or self-balancing) tree.  They are BSTs, but they have an additional property that must be maintained -

The height of any left and right subtree can differ by at most 1.
---?image=./trees/images/bst_and_avl.png&size=50% auto
Which of these is an AVL?
---
