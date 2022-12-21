
https://codeforces.com/blog/entry/15296
comment 1:


Dynamic connectivity Offline : 

in a graph of N vertices, we have k operations which can be of type

1. add + (adds edges between two nodes)
2. removes - (removes edges between two nodes, the edge removed will be present either in th intial graph edge or one of the added edges) 
3. ? what is the number of connected components 


preprocess : 
let X set of edges, which are always present in it (that were originally there and were no requests for 
their removal). 
Let's compress each connected component formed from such edges in one vertex and construct a new graph of these vertices. 
Also delete all vertices that are not mentioned in the list of requests.

The resultant graph will have some group of vertices which are connected later on, or removed later on..therefore at max 2K vertices 

Now with these vertices (each vertice is a group of connected vertices that are not modified)




if there are k queries and let each query represent a state of graph (moment of time)

we make a segment tree on top of k + 1 vertices, 1 initial state 

For edges that are removes, lets take ith edge: they are either removed from added eges or edges from graph itself when

lets make a map for each edge where we store the addition or removal of itt:

it will be like 
      add-i1 remove-i2 add-i3 remove-i4
         or
      remove-j1 add-j2 reomve-j3 add-j4 

we iterate for each edge edge
   [1...i1)    [i1....i2)  [i2 ----i3)   [i3-- i4).
    unavailable  available unavailable   available
or
   [1... j1)[j1....j2)  [j2....j3)
    available  unavailable  available

inesrt each operation in a range that we insert k operation in log k nodes.
only push available operation

We do not do anything for ? operartion.





Theory: 
dsu and rolback operation is possible if we reverse steps

this is just to mimic disconnect(a,b) after connect(a,b).b
when connect(a,b) is run we can store all operations in memory on a stack and then undo them
for disconnect(a,b).

note: this is not like we can disconnect(a,b) at any time, as at a random point we wont know what will happen will these result in two componets or just one.

But if order of connects is presevered we can unorder or go back in time 

connect(a,b) connect(b,c) connect(a,c) connect(a,d)
 
we can then go back if we undo memory operations in order for connect(a,d) connect(a,c) connect(b,c) connect(a,b)


end of above theory 

Then we traverse the segment tree by using DFS starting from the root. During the traversal we maintain the connected components of the graph using disjoint sets. When we enter a segment tree node, we perform a Union operation for each edge which is stored in that node.
 We also store the rollback operation details in a stack of operations so that, when we exit a segment tree node, we are able to undo all the Union operations performed when entering the node.
 Before exiting a leaf node of the segment tree node which corresponds to a "?" operation we have the answer as the number of sets in the disjoint sets data structure (which we maintain as a separate variable which is updated when a Union is successful and when a Union is undone).

we enter each node once hence klogk, each node we do operations of merging in a dsu 
we inseted such opeartion klogk times so overall 
klogk + klogk 
undo takes the same time as we reversing memory operations, we will need extra space for storing all undo operations.