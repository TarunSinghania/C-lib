#include <bits/stdc++. h> 
using namespace std; 
const int MAX N = 10000; const int LOG = 14; 
vector‹int> children [MAX N] ;
int depth [MAX N];

void dfs(int a) {
 for(int b : children[a]){
   depth [b] = depth [a] + 1; up[b][0] = a;  // a is parent of b
   dfs(b); 
  }  
}

 int get_lca(int a, int b) { 
 	if(depth[a] < depth[b])swap (a, b); 
 	while(depth[a] > depth[b]){
 		a = up[a][0];
 	while(a != b){
 		a = up[a][0]; 
 		b = up[b][0];
 	}
}

//can replce go up and search by using binary lifting 