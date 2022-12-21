#include<bits/stdc++.h>
using namespace std;

int dp[10][10][10];
int vis[10][10][10];


class GameState{
    public:
    int sz;
    int mxh;//max height of a coloumn
    vector<int> h;
    GameState(int N, int a[], int hmax){
        h.resize(N);
        sz = N;
        mxh= hmax;
        for(int i =0 ; i < N ; i++){
            h[i] = a[i];
        }
    }
};
void print(GameState g,int type){
    for(int i = 0 ; i < g.sz ; i++){
        cout<<g.h[i]<<" ";
    }
    cout<<"->"<<type<<endl;
}
 
//if at least one step leads to a losing state -> winner 
//if all leads to winning state -> loose state
int whowins(GameState s){
    int this_type = 0;//lets consider it as loosing state
    vis[s.h[0]][s.h[1]][s.h[2]] = 1;
    for(int i = 0; i < s.sz ; i++){
        int curh = s.h[i];
        GameState n = s;
        for(int dec = 1 ; dec <= s.h[i] ; dec++){
            n.h[i]--;
            if(vis[n.h[0]][n.h[1]][n.h[2]] == 0)
                whowins(n);
            int next_type  = dp[n.h[0]][n.h[1]][n.h[2]];
            if(next_type == 0) this_type = 1;
        }
    }
    dp[s.h[0]][s.h[1]][s.h[2]] = this_type;
    print(s,this_type);
    return this_type;//looser state
    //return player^1; //base case no turn left
}
int main(){
    int a[3] ={1,2,3};
    GameState start(3,a,3);
 
    
    //non memoized
    cout<<whowins(start);
}