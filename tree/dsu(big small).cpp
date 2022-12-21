#include <bits/stdc++.h> 
using namespace std;
#define MAX 100005
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define ll long long
#define LOG_MAX 20

1 2 5 6 11 3 7 4 8 12 15 13 9 14 10

is it possible we have second occurence of z in for start of x and  and y but not first of z


x -> subtreee   before we go into y  ka subtreee we have z

    z
--x   y 
z -> x -> z -> y -> x

X
a
b
c d
y e

x -> a -> b -c -d -e -d -y - c 
      --      
    lca
  --   --
 --     --    
x     --  

-- lca ---x --lca

int main(){
  speed;
  cin>>N;
  for(int i = 1; i <= N - 1; i++){
    int a, b;
    cin>> a>> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }  
  dfs(1,-1);
  HLD(1,-1,1);

}


