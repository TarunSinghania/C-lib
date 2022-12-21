
The set V of vertices of the graph is fixed, but the set E of edges can change. The three cases, in order of difficulty, are:

Edges are only added to the graph (this can be called incremental connectivity);
Edges are only deleted from the graph (this can be called decremental connectivity);
Edges can be either added or deleted (this can be called fully dynamic connectivity).



Incremental connectivity
- Disjoint-set data structure. (works online offline, for online a extra datastrucutrure to hold nodes is needed)

Decremental connectivity
case 1: 
- Acyclic graphs (forests) 
   - dsu will help us get the forests (Set of tree/Acyclic graphs) 
   - if a edge (u,v) is removed :
      case (a) : edge might not be inforest, connectivity by other edges
      case (b) : edge can be present in forest 
         -case (a)
         remove edge directly, connectivity does not change 
         -case (b)
          start bfs/dfs from u
          start bfs/dfs from v
          do it in an interleaved manner make a step of first scan, then a step of the second scan, then a step of the first scan, etc.
          Suppose the first scan that terminates is the scan from u (so we know that the tree containing u is the smaller one). Assign a new component name to every node in the subtree of 


