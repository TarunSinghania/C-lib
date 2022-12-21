//for undirected there is no cross edge or tree edge and only back edge
//tested
//maintaining level data is enough
//the tin version will also work but over work


#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
int n,m ; 
set<pair<int,int> > ans;
vector<bool> vis;
int l[MAX];
int MAN[MAX];
vector<int> adj[MAX];
void IS_BRIDGE(int a,int b)
{
    if(a>b)
        swap(a,b);
    cout<<a<<" "<<b<<endl;
    ans.insert({a,b});
}
 
void dfs(int v, int p) {
    vis[v] = true;
    l[v] = l[p] + 1;
    MAN[v] = l[v];
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            MAN[v] = min(MAN[v], l[to]);
        } else {
            dfs(to, v);
            MAN[v] = min(MAN[v], MAN[to]);
            if (MAN[to] > l[v])
                IS_BRIDGE(v, to);
        }
    }
  //  cout<<v<<" "<<l[v]<<" "<<MAN[v]<<endl;
}
 
void find_bridges() {
    vis.assign(n+1, false);
    //if graph can havemultiple compnents handle carefully
    for(int i = 1; i <= n ; i++){
        if(!vis[i])dfs(i,0);
    }
}
 
 
 
 
int main()
{
    speed;
    cin>>n>>m; 
    for(int i =0 ; i < m ; i++)
    {
        int a,b;
        cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
    }
    find_bridges();
  
}

