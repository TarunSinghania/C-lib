https://codeforces.com/blog/entry/81661


xenia and tree:



question : 
a tree of 𝑛 vertices, where each vertex is initially blue except for vertex 0, which is red. There are two types of queries 
1. Set the color of a vertex 𝑣 to red
2. Given a vertex 𝑣 compute the distance to the closest red vertex to 𝑣 (which could be itself)

Brute Force: 
for each vertex 𝑣, 
	the closest red node to it that's' within its subtree, and call it 𝑏𝑒𝑠𝑡[𝑣].

For any vertex v

	there are two cases:

  	The closest node is in 𝑣 s subtree. In this case, we use the value 𝑏𝑒𝑠𝑡[𝑣]
     that we already have stored.

The closest node is not in 𝑣s subtree. Then its in the subtree of some ancestor 𝑢 of 𝑣 but not in 𝑣s subtree (and of course the distance is 𝑏𝑒𝑠𝑡[𝑢] since we want the closest red node in 𝑢s subtree). Therefore the path from the closest node to 𝑣 goes through 𝑢, so we can represent its length as 𝑏𝑒𝑠𝑡[𝑢]+𝑑𝑖𝑠𝑡(𝑢,𝑣). "Whats most important here is that the path goes through u"


Observation 1: 

Each subtree in the centroid tree forms a connected component in the original tree.

Observation 2: 
every other vertex not part of V's' subtree (in the centroid tree) is either an ancestor of 𝑣 in the centroid tree or "blocked off" from 𝑣 by at least one such ancestor.

The trick is an update will only be done on ancestors and while querying

when a node is changed from blue to red : we update all the ancestors minimum distance to a red can be min(ancestor_min, d(ancestor, node))
    

min distance for any node calculation: 

  min_distance in the subtree to a node,

  or else distance to any ancestor + ancestor_min





