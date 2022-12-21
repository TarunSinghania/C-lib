//not tested;
#include <bits/stdc++.h> 
using namespace std;
#define MAXN 100005
stack<int> s;
vector<int> tp;
vector<int> vis;

vector<int> adj[MAXN];
void dfs(int i){
	vis[i] = true;
	for(auto x : adj[i]){
		if(!vis[x])
			dfs(x);
	}
	s.push(i);
}

void topsort(){
	vis.resize(MAXN, false);
	for(int i = 1; i <= MAXN; i++){
		if(!vis[i])
			dfs(i);
	}
	while(!s.empty()){
		tp.push_back(s.top());
		s.pop();
	}
}

int32_t main(){

 	int t;

 	adj[1].push_back(2);
 	adj[2].push_back(3);
 	adj[3].push_back(4);
 	adj[5].push_back(3);
 	topsort();
	return 0;
}