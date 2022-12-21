//for undirected there is no cross edge or tree edge and only back edge
//untested
//maintaining level data is enough
//the tin version will also work but over work

#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)

int n,m ; 
set<int> ans;
vector<bool> vis;
int l[MAX];
int MAN[MAX];
vector<int> adj[MAX];

 
void dfs(int v, int p) {
    vis[v] = true;
    l[v] = l[p] + 1;
    MAN[v] = l[v];
    int child = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            MAN[v] = min(MAN[v], l[to]);
        } else {
            child++;
            dfs(to, v);
            MAN[v] = min(MAN[v], MAN[to]);
            if (MAN[to] > l[v] && p != 0)
                ans.insert(to);
        }
    }
    if(p == 0 && child > 1){
    ans.insert(v);
    }
  //  cout<<v<<" "<<l[v]<<" "<<MAN[v]<<endl;
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
    vis.assign(n+1, false);
    //beware if it has more than one component
    dfs(1,0);
}

