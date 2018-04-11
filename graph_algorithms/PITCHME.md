---
CIS 263 - Structure of Programming Languages

Ira Woodring

***

**Dynamic Programming**

(Chapter 9 in Weiss)
---
A graph is a structure, typically defined as G=(V,E) where V is a set of vertices and E is a set of edges between them.

Graphs can be directed or undirected.
---
A directed graph means that for two vertices *a*, and *b* that *a* has a path to *b* but not necessarily from *b* to *a* (there could be one but doesn't have to be).
---
A **path** in a graph is some sequence of vertices from one vertex to another.  Mathematically we would say that a path is *w1, w2, w3, ..., wn* such that (*w(i), w(i+1)*)∈E for all i from 1 to N.

The **length** of a path is the number of edges on the path (which is the number of vertices touched minus 1).
---
We have a **loop** if a path contains an edge from some vertex *v* to *v*.

We say we have a **cycle** if we have a path of at least length 1 such that the first vertex is also the last vertex in the path.
---
A directed graph with no cycles is called acyclic, and we use the term **DAG** for a directed, acyclic graph.
---
A graph is **connected** if it has a path from every vertex to every other vertex.  A **complete graph** is a graph that has edges between every pair of edges.
---
There are two main ways that we store graphs for use in our algorithms.  They are:

- adjacency matrices
- adjacency lists
---
An adjacency matrix is just a two-dimensional array, here called C[][].  In C[i][j] we store either a true or false value to indicate connectivity between vertices i and j, or a numerical weight.

Because we require O(|V|^2) memory spaces to store all the information for a graph, this method can consume a lot of memory if our graph is large.
---
If the graph is **dense** this is ok (dense meaning there are many edges).  If the edge is **sparse** too much memory is wasted.

For most of the algorithms we will study in this class, our graphs are sparse.
---
Sparse graphs are good candidates for adjacency lists.  For these we keep a list for each vertex of the edges it has to other vertices.
---?image=./graph_algorithms/images/adjacency_list.png&size=50% auto
---
The first use of graphs we will visit is the problem of finding a **topological sort**.  A topological sort occurs when we order vertices so that a if there exists a path from v(i) to v(j) that v(j) appears after v(i).
---
We may use a topological sort for problem like finding a schedule at a University.  If we model a Computer Science program as a graph for instance, a topological sort could place classes that require prerequisites after their prerequisites.

Note there must be no cycles in the graph of we wish to perform a topological sort.
---?image=./graph_algorithms/images/topological_sort.png&size=50% auto
---
There are multiple ways of performing a topological sort.  Our book describes Kahn's algorithm (1962).  This algorithm first finds the **indegree** of vertices, meanins the number of edges leading to this node.

We first find the nodes with indegree of 0.
---
For each vertex of indegree 0 we print it, remove it and its edges, and do the same for the rest of the graph.

Let's practice!
---?image=./graph_algorithms/images/course_graph.png&size=50% auto
---
Another method of performing a topological sort is a modified Depth First Search (DFS).

With this algorithm we can start anywhere.  We will use a stack.

For every vertex:
  - mark the vertex visited
  - with the chosen vertex recursively call topological sort on all adjacent vertices.
  - put node on the stack.

Pop all the nodes off the stack for the result.
---
Obviously there are multiple valid topological sorts for many graphs.  In the course list for instance, we could take MAC 3311 or COP 3210 first.
---
We use a topological sort for many type of problems.  Besides the problem of picking classes we saw above, we might also use a topological sort for

- build dependencies
- scheduling tasks
- package management
---
The next problem we will be studying is the Shortest-Path problem.  This is the problem of of finding the shortest distance from one node to all other nodes in a graph.  This may be used for more than just finding distances though.  For instance, we might calculate how closely linked people are in a social network, etc.
---
The first variant of this is the Unweighted Shortest Paths problem.  For this problem we are not concerned with weight, but the number of edges contained in the path.
---
It turns out that this is fairly simple; we merely need to perform a Breadth First Search.  Staring at some node we will find all paths of length 0.  Then we will find paths of length 1.  This is fairly simple; we need only examine the paths of length 0 and what they connect to.
---
To find paths of length 2 we start with the paths of length 1, etc., until all paths are calculated:
---?image=./graph_algorithms/images/bfs-1.png&size=50% auto
---?image=./graph_algorithms/images/bfs-2.png&size=50% auto
---?image=./graph_algorithms/images/bfs-3.png&size=50% auto
---?image=./graph_algorithms/images/bfs-4.png&size=50% auto
---
This is easy to draw, but how do we teach a computer to do it?
---
If we have the graph stored as an adjacency list, one easy way is the following algorithm (pseudocode):

```
void Graph::unweighted( Vertex s ){
  Queue<Vertex> q;

  for each Vertex v {
    v.dist = INFINITY;
  }

  s.dist = 0;
  q.enqueue( s );

  while( !q.isEmpty() ){
    Vertex v = q.dequeue();

    for each Vertex w adjacent to v {
      if( w.dist == INFINITY ){
        w.dist = v.dist + 1;
        w.path = v;
        q.enqueue( w );
      }
    }
  }
}
```
---
This algorithm relies upon each vertex keeping a distance.  This distance is the shortest distance to this node from where we started.

We put the initial node on a queue, with a distance of 0.

Then we start a loop where we pop the front element from the queue, iterate over its children, give them a distance of the current node + 1 ONLY if they don't already have a smaller number (implying they have a shortest path already), and place them on the queue.  We continue until the queue is empty.
---
Let's practice on the board with this graph:

```C
1: 2, 4
2: 4, 5
3: 1, 6
4: 6, 7
5: 7
6:
7: 6
```

We will use a queue but also a two dimensional array for some intermediate values (for the purpose of simplification).
