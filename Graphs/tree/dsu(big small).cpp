//cf submission 165268342 - Lomsat gelral
#include <bits/stdc++.h> 
using namespace std;
#define MAX 100005
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define ll long long
#define LOG_MAX 20
int N;  
int col[MAX];
vector<int> adj[MAX];
vector<int> *v[MAX];
int sz[MAX];
//global array declare

void dfs(int n, int p){
    sz[n] += 1;
    for(auto x : adj[n]){
        if(x != p)
            dfs(x,n), sz[n]+=sz[x];
    }
}

void add(int node){
//modify global array
  
}

void remove(int node){
//modify global array
  

}

void HLD(int n, int p, bool keep){
    int big_child = -1; int big_size = -1;

    for(auto x : adj[n]){
        if(x != p){
            if(sz[x] > big_size)
            {
                big_size = sz[x]; big_child = x;
            }
        }
    }

    for(auto x : adj[n]){
        if( x != p && x != big_child){
            HLD(x, n, 0);
        }
    }

    if(big_child != -1){
        HLD(big_child, n, 1);
        v[n] = v[big_child];
    }else{
        v[n] = new vector<int> ();
    }

    (*v[n]).push_back(n);
    add(n);

    for(auto x : adj[n]){
        if(x!=p && x != big_child)
        {
            for(auto y : *v[x]){
                   (*v[n]).push_back(y);
                   add(y);
            }
        }
    }

    {
    //check here on global array that you make

    }

    if(keep == 0){
        for(auto x : *v[n]){
                remove(x);
        }
    }

}



int main(){
  speed;
  cin>>N;
  for(int i = 1; i <= N - 1; i++){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }  
  dfs(1,-1);
  HLD(1,-1,1);

}


