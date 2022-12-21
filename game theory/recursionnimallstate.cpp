#include<bits/stdc++.h>
using namespace std;
 
class GameState{
    public:
    int sz;
    vector<int> h;
    GameState(int N, int a[]){
        h.resize(N);
        sz = N;
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
 
    for(int i = 0; i < s.sz ; i++){
        int curh = s.h[i];
        GameState n = s;
        for(int dec = 1 ; dec <= s.h[i] ; dec++){
            n.h[i]--;
            int next_type  = whowins(n);
            if(next_type == 0) this_type = 1;
        }
    }
    print(s,this_type);
    return this_type;//looser state
    //return player^1; //base case no turn left
}
int main(){
    int a[3] ={1,2,3};
    GameState start(3,a);
 
    
    //non memoized
    cout<<whowins(start);
}