#include <bits/stdc++.h>
using namespace std;

//from in[i] to out[i] we have all nodes in subtree of i including i
//if we want only subtree in[i] + 1, out[i] (check if in[i] + 1 > out[i] then no elements)
#define MAX 10005
int a[MAX];
int in[MAX];
int out[MAX];
bool vis[MAX];
int timer = 1;
vector<int> adj[MAX];
void euler(int n){
    in[n] = ++timer;
    a[timer] = n;
    for(auto x : adj[n]){
        if(!vis[x]){
            euler(x);
        }
    }
    out[n] = timer;
}


int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m ; i++){
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
    }
    euler(1);
    cout<<in[1]<<" "<<out[1]<<endl;
}



