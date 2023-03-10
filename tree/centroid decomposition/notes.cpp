https://codeforces.com/blog/entry/81661


xenia and tree:



question : 
a tree of ð vertices, where each vertex is initially blue except for vertex 0, which is red. There are two types of queries 
1. Set the color of a vertex ðĢ to red
2. Given a vertex ðĢ compute the distance to the closest red vertex to ðĢ (which could be itself)

Brute Force: 
for each vertex ðĢ, 
	the closest red node to it that's' within its subtree, and call it ððð ðĄ[ðĢ].

For any vertex v

	there are two cases:

  	The closest node is in ðĢ s subtree. In this case, we use the value ððð ðĄ[ðĢ]
     that we already have stored.

The closest node is not in ðĢs subtree. Then its in the subtree of some ancestor ðĒ of ðĢ but not in ðĢs subtree (and of course the distance is ððð ðĄ[ðĒ] since we want the closest red node in ðĒs subtree). Therefore the path from the closest node to ðĢ goes through ðĒ, so we can represent its length as ððð ðĄ[ðĒ]+ððð ðĄ(ðĒ,ðĢ). "Whats most important here is that the path goes through u"


Observation 1: 

Each subtree in the centroid tree forms a connected component in the original tree.

Observation 2: 
every other vertex not part of V's' subtree (in the centroid tree) is either an ancestor of ðĢ in the centroid tree or "blocked off" from ðĢ by at least one such ancestor.

The trick is an update will only be done on ancestors and while querying

when a node is changed from blue to red : we update all the ancestors minimum distance to a red can be min(ancestor_min, d(ancestor, node))
    

min distance for any node calculation: 

  min_distance in the subtree to a node,

  or else distance to any ancestor + ancestor_min





