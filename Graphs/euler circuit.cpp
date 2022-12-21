//for unidirected graphs
//A Eulerian path is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle.
//An Eulerian cycle exists if and only if the degrees of all vertices are even. And an Eulerian path exists if and only if the number of vertices with odd degrees is two (or zero, in the case of the existence of a Eulerian cycle).
//First, the program checks the degree of vertices: if there are no vertices with an odd degree, then the graph has an Euler cycle, if there are vertices with an odd degree, then in the graph there is only an Euler path (but no Euler cycle), if there are more than such vertices, then in the graph there is no Euler cycle or Euler path
//in addition, of course, the graph must be sufficiently connected (i.e., if you remove all isolated vertices from it, you should get a connected graph).

//for directed graph
//https://www.youtube.com/watch?v=xR4sGgwtR2I

// Hierholzer's algorithm  :Looking for all cycles and combining them can be done with a simple recursive procedure 
//procedure FindEulerPath(V)
  // 1. iterate through all the edges outgoing from vertex V;
  //      remove this edge from the graph,
  //      and call FindEulerPath from the second end of this edge;
  // 2. add vertex V to the answer.
