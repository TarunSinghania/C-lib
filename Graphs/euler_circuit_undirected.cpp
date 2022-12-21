/**
    The Algorithm below is known as Heirholzer's Algorithm. It runs in O(V + E).
 
    The algorithm finds an Euler Tour or an Euler Circuit depending on whether the
    graph has 0 or 2 nodes with odd degree. If the graph is not Eulerian, it still
    returns some list, so make sure to first check that the graph is Eulerian.
 
    A connected graph has an Euler Path (A path that uses all edges but starts and ends at
    different nodes) if it has exactly 2 nodes with odd degree. While calling find_path()
    make sure you ensure that you call it with an ODD degree node since the path must
    start/end there.
 
    A connected graph has an Euler Circuit (A circuit that uses all edges and starts and ends
    at the same node) if all nodes have even degree. You can call find_path() with any
    node here.
 
    This algorithm handles self loops and multiple edges as well, but only works on undirected
    graphs.
**/


#include <bits/stdc++.h>
using namespace std;
#define ll long long 


struct Edge;
typedef list<Edge>::iterator iter;
 
struct Edge
{
    int next_vertex;
    iter reverse_edge;
 
    Edge(int next_vertex)
        :next_vertex(next_vertex)
        { }
};

int n;
ll ans;
const int max_vertices =  200005 ;
int num_vertices;
list<Edge> adj[max_vertices];       
 
vector<int> path;
 
void find_path(int v)
{
    while(adj[v].size() > 0)
    {

        int vn = adj[v].front().next_vertex;
        adj[vn].erase(adj[v].front().reverse_edge);
        adj[v].pop_front();
        find_path(vn);
    }
    path.push_back(v);
}
 
void add_edge(int a, int b)
{
    adj[a].push_front(Edge(b));
    iter ita = adj[a].begin();
    adj[b].push_front(Edge(a));
    iter itb = adj[b].begin();
    ita->reverse_edge = itb;
    itb->reverse_edge = ita;
}

void euler_circuit(int n){
    find_path(n);
}

void euler_path(){
    //todo : start from any odd degree vertice you will end at odd end vertice

}



int main(){
    

}