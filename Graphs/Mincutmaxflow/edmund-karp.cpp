//https://codeforces.com/problemset/problem/546/E
#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define INF 1000000000
#define MAX_N 600
#define ll long long

vector<int> adj[MAX_N];
int cap[MAX_N][MAX_N];
int parent[MAX_N];
int v, e;
int s, t;

int BFSH(){
    queue<pair<int,int> > q;
    parent[s] = -1;
    q.push({s,INF});
    int new_flow = 0;
    while(!q.empty()){
        int node = q.front().first; int _cap = q.front().second; 
        q.pop();
        for(auto next_node : adj[node]){
            if(parent[next_node] == 0 && cap[node][next_node] > 0){
                parent[next_node] = node;
                int next_node_cap = min(_cap, cap[node][next_node]);
                q.push({next_node, next_node_cap});
                if(next_node == t){new_flow = next_node_cap; return new_flow;}
            }
        }
    }
    return new_flow;
}

inline int BFS()
{
    for(int i = 1; i<= t; i++)parent[i] = 0;
    stack<int> dfss; stack<int> lcs;//dfs stack , link capacity stack
    parent[s] = -1;
    int new_flow = BFSH();
    if (new_flow > 0)
    {
        int currNode = t;
        while (currNode != s)
        {
            cap[parent[currNode]][currNode] -= new_flow;
            cap[currNode][parent[currNode]] += new_flow;
            currNode = parent[currNode];
        }
    }
    return new_flow;
}

inline int FordFulkerson()
{
    
    int flow = 0;
    while(true){
        int cflow = BFS();
        if(cflow == 0)break;
        flow+=cflow;
    }
    return flow;
    
}

int main()
{
	cin>>v>>e;
	s = 1;
	t = 1+v+v+1;
	int totalinput = 0;
	int totaloutput = 0;
	int maxcapacity = 0;
	for(int i = 1 ; i <= v ;i++){
		int c;cin>>c;
		totalinput+=c;
		adj[1].pb(1+i); adj[1+i].pb(1);
		cap[1][1+i] = c;
	}
	for(int i = 1 ;i <= v; i++){
		int c;cin>>c;
		adj[1+v+i].pb(t);adj[t].pb(1+v+i);
		cap[1+v+i][t] = c;
		maxcapacity += c;
	}
	if(maxcapacity != totalinput){
		cout<<"NO"<<endl;
		exit(0);
	}
	for(int i =1 ; i <= v ; i++){
		adj[1+i].pb(1+v+i);	adj[1+v+i].pb(1+i);
		cap[1+i][1+v+i] = 200;
	}

    for(int i  =0 ; i < e ; i++){
    	int a,b;
    	cin>>a>>b;
    	adj[1+a].pb(1+v+b);adj[1+v+b].pb(1+a);
    	cap[1+a][1+v+b]=200;

    	adj[1+b].pb(1+v+a);	adj[1+v+a].pb(1+b);
    	cap[1+b][1+v+a]=200;
    }	
    totaloutput = FordFulkerson();
    
    if(totaloutput == totalinput){
    	cout<<"YES"<<endl;
    	for(int i = 2; i<=1+v ; i++){
    		for(int j = 1+v+1 ; j<=1+v+v ;j++){
    			if(cap[i][j] > 0 && cap[i][j] < 200){
    			 	cout<<200-cap[i][j]<<" ";
    			}
    			else
    			cout<<0<<" ";
    		}
    		cout<<endl;
    	}
    }	
	else{
    	
		cout<<"NO"<<endl;
	} 	

    return 0;
}