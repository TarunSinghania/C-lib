https://courses.csail.mit.edu/6.851/spring12/lectures/L19.html?notes=2

In advance ds MIT (todo)

• Fully Dynamic. Supports insertion and deletion of vertices and edges.
• Incremental. Supports only insertions of vertices and edges.
• Decremental. Supports only deletions of vertices and edges.

Forests:

we see link cut trees, splay trees link cut trees can be implemnted in many ways one of them is to use splay tree
  
Splay tree is self-balancing BST.
  It has one interesting difference, however: whenever an element is looked up in the tree, the splay tree reorganizes to move that element to the root of the tree, without breaking the binary search tree invariant. If the next lookup request is for the same element, it can be returned immediately. In general, if a small number of elements are being heavily used, they will tend to be found near the top of the tree and are thus found quickly.


link-cut tree offers:

  	The link-cut tree data structure represents a rooted forest (a collection of rooted trees) and can perform the following operations in 𝑂(log𝑛) amortized time (here, a node represents a vertex of the tree):

     link(par, child): Attach a tree (child) as a child of another tree's node (par).

     cut(node): Detach node's subtree from node's parent.

     find_root(node): Find the root of a node.

     path aggregate(v) – Returns an aggregate, such as max/min/sum, of the weights of the edges
on the path from the root of the tree to node v. It is also possible to augment the data
structure to return many kinds of statistics about the pat

function find_root() can be used to check if u and v are connected 

Overall For trees: we can support O(log n) time for queries and updates using Euler-Tour trees (discussed not yet read) or Link-Cut trees. If the trees are only decremental, then we can support queries in constant time(covered in lec).

Graphs:

Planar graphs. Eppstein et al. have proven that we can attain O(log n) queries and up-
dates (no two edges interscting)

For the incremental data structure, the best result we have is Θ(α(m, n)) using union-
find 

In 2000 Thorup showed how to obtain O(log n(log log n)3) updates and O(log n/ log log log n)
queries 

For the decremental data structure, we have a O(m log n + polylogn + #queries) solution,
which essentially amounts to an O(log n) solution for dense graphs [124].

OPEN: It remains an open problem whether O(log n) queries and updates are attainable for
general graphs.



When we go to offline queries i.e all queries and upates are knwon from before then we can check diploma for better complexity.
