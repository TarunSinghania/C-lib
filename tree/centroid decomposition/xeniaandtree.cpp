#include <bits/stdc++.h> 
using namespace std;
#define MAX 100005
int n,m;

set<int> adj[MAX];
vector<int> ortree[MAX];
int cdparent[MAX];int oparent[MAX];
int op[MAX][26];
int h[MAX];
vector<int> cdtree[MAX];
int sz[MAX];
int mndis[MAX];
int root;

void dfs(int n, int p, int hi){
    mndis[n] = INT_MAX;
    oparent[n] = p;
    h[n] = hi;
    for(auto x : adj[n]){
        if(x != p){
            dfs(x, n, hi + 1);
        }
    }
}

void preprocess(){
    dfs(1,-1, 1);
    for(int j = 0; j < 26 ; j++){
        for(int i =1 ; i <= n ; i++){
            op[i][j] = -1;
        }
    }
    for(int i =1 ; i <= n ; i++){
            op[i][0] = oparent[i];
    }
    for(int j = 1; j < 26 ; j++){
        for(int i =1 ; i <= n ; i++){
            if(op[i][j-1]!= -1)
            op[i][j] = op[op[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b){
    if(h[a] > h[b])swap(a,b);

    int dif = h[b] - h[a];

    for(int i = 25; i >= 0; i--){
        if(dif & (1<<i)){
            b = op[b][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = 25; i >= 0 ; i--){
        if(op[a][i]!=-1 && (op[a][i] != op[b][i])){
            a = op[a][i];
            b = op[b][i];
        }
    }
    return op[a][0];
}
int dis(int a, int b){
    int g = lca(a, b);
    return h[a] + h[b] - h[g] - h[g];
}

int dfssz(int a, int p){
    sz[a] = 1;
    for(auto x : adj[a]){
        if(x != p)
            sz[a] += dfssz(x,a);
    }
    return sz[a];
}

int getcentriod(int a, int p, int n){
    for(auto x : adj[a]){
        if(x != p && sz[x] > n/2){
            return getcentriod(x, a, n);
        }
    }
    return a;
}

void divide(int a, int p){
    int n = dfssz(a,p);
    int c = getcentriod(a,p,n);
    if( p != -1){
        cdparent[c] = p;
        cdtree[p].push_back(c);
        cdtree[c].push_back(p);
    }else{
        root = c;
        cdparent[c] = -1;
    }
    vector<int> temp(adj[c].begin(), adj[c].end());
    for(auto x : temp){
        adj[x].erase(c);
        adj[c].erase(x);
        divide(x, c);
    }
}


void decompose(){
    divide(1,-1);
}

void update(int u){
    int d = 0;
    mndis[u] = d;
    int v = u;
    while(cdparent[v] != -1){
        v = cdparent[v];
        d = dis(v, u);
        mndis[v] = min(mndis[v], d);
    }
}
int query(int u){
    int ans = mndis[u];
    int v = u;
    while(cdparent[v] != -1){
        v = cdparent[v];
        if(mndis[v]!=INT_MAX){
        int curdis = dis(v,u) + mndis[v];
        ans = min(ans, curdis);
        }

    }
    return ans;
}

int main(){
    cin>>n>>m;
    for(int i = 0 ; i < n  - 1; i++){
        int u , v;
        cin>>u >> v;
        ortree[u].push_back(v);
        ortree[v].push_back(u);
        adj[u].insert(v);
        adj[v].insert(u);
       
    }   
    preprocess();
    decompose();
    int q[m][2];
   
    update(1);
    // for(int i = 1; i <= n ; i++){
    //     cout<<query(i)<<endl;
    // }

    for(int i =0  ; i < m ; i++)    
    {
        int t; int v;
        cin>>t>>v;
        if(t == 1){
            //b to r
            update(v);
        }else{
            cout<<query(v)<<endl;          
        }
    }



    return 0;
}