#define fr(i,a,b) for(int i =a ; i < b; i++)
bool dfsu(int j,int col[],vector<int> adj[])
{
    col[j]=1;
    for(auto x : adj[j])
    {
        if(col[x] == 1)
            return true;
        if(col[x] == 0){
            if(dfsu(x,col,adj))
                return true;
        }
    }
    col[j]=2;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int colour[V+1]={0};
    
    fr(i,0,V)
    {
        if(colour[i]==0)
            if(dfsu(i,colour,adj))
                return true;
    }
      
    return false;
}


//check if DAG : 
//check if cycle exists 
//or check if back edge exits in dfs tree: 
//note : in dfs tree of a undirected graph there is no cross edge or forwad edge 
//theres only tree edge and back edge
//in directed everything exists

//tree edge - edges which are there in tree 
//fdorward (directed from ancestor to descendant) not in tree
//back (directed from descendant to ancestor), or
//cross (joins 2 unrelated vertices)
//key fact:
//any cross edge is directed from right to left

//while making graph check for arrival and depature times 
// edge u->v 
// a. a tree edge or forward edge if and only if u. discover < v.discover < v.finsished<  u finished 
//to differentiate between tree and forward use visited for tree edges the vertex v is not visited when in discovered 
// b. a back edge if and only if v.discovered < u.discovereed < u. finished < v.finsihed
/// c. a cross edge if and only if v.discver < v.finished < u.disocer < u.finshed 

//we have a cycle if we have a back edge 
//the above properities for cross edge exists on a single dfs tree
//if we have a graph with multiple dfs tree, (forest) cross edged will be different
//https://www.cs.yale.edu/homes/aspnes/pinewiki/DepthFirstSearch.html

//for shortest cyclce :
//undirected unweighted : take dfs tree and cost off each cycle = depth + 1 back edge 
//undirected weighted: 
//For each edge(u,v,w) : Delete it and run Dijkstra from one of its endpoints and let T be the distance between u and v, the answer is the minimum over all T+w. Since we are performing M dijkstras, the complexity is O(M^2 log N)
//directed eeighted: 
//For each edge(u,v,w) : Delete it and run Dijkstra from one of its endpoints and let T be the distance between v and u, starting v. the answer is the minimum over all T+w.
//Since we are performing M dijkstras, the complexity is O(M^2 log N)

// idea 2(this wont work) 
//for every node u:
    //run dhisktra - and mark edges used in shortest path 
    //for each non used edge that starts at some vertice v to u
    // ans = min (ans, dis(u,v) + w(v,u))
//it should work casue every cycle of minimum weight will have all vertice points satisfy this
//N((Mlogn) + M)
// 1 2
// 2 3
// 3 4
// 4 1
//when we take shortest path from each node u eg. 1 : the onlt unused edge is 2, 3
//we have no way know the shortest distance betwen 2, 3
//contradiction the shortest cycle might look like : 
//x ---- start node --- y and left edge x, y
//if we take each painging then n2 