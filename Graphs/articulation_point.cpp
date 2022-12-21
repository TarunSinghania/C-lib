//can work on undirected for sure
//for directed if there is a single 
////works for undirected graph only tree edge, backedge
//for directed graphs which has all 
//forward edge, tree edge, back edge, cross edge,
//it depends on which node we start and we can have multiple
//dfs trees, a forest connected by cross edges on which this algo wont work

//idea:


#include<bits/stdc++.h> 
using namespace std;
#define MAX 10005
int v; 
int n,m;

vector<int> adj[MAX];

set<int> articulation_points;

int timer;
int in[MAX];
//dp here stores minimum ancestral time (minimum inserted time that can be reached that is connected by the node or any of the nodes in the subtree)
int dp[MAX];
void visit(int node,int p){
  in[node] = ++timer;
  dp[node] = timer;
  int child = 0;
  for(auto next : adj[node])
  { 
    if(next == p)continue;
    if(in[next] == 0){
      child++;  
      visit(next,node);
      dp[node] = min(dp[node],dp[next]);
      if(dp[next] >= in[node] && p != 0){
      articulation_points.insert(node);
      }
    }else{
      dp[node] = min(dp[node],in[next]); 
    }    
  }
  if(p == 0 && child > 1){
    articulation_points.insert(node);
  }
}

void articulation_point(int start){
    visit(start,0);
}

int main(){


  return 0;
}
