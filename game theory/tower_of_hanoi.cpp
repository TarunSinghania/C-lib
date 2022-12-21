#include<bits/stdc++.h>
using namespace std;
#define N 6
#pragma comment(linker, "/STACK:268435456");
int a[N] = {1,2,3,4,5,6,};
//conifg tower on which ith ring belong to 
int initialconfig[N] = {0,0,1,1,2,2};
int finalconfig[N] = {2,2,1,1,0,0};

bool cmp(const int& x, const int &y){
            return a[x] < a[y];
}
set <long long> vis; 
map<long long,long long> from;
map<long long,pair<int,int> > prev_move;
class GameState{
      public:
        int conf[N];
        vector<int> v[3];
        
        GameState(int config[]){
            for(int i = 0; i < N ; i++){
            conf[i] = config[i];
            v[conf[i]].push_back(i);
            }
            for(int i = 0 ; i < 3; i++)
            sort(v[i].begin(),v[i].end(), cmp);
        }
        long long id(){
            long long j = 0; long long base =1;
            for(int i = N-1 ; i >=0 ; i--){
                j = j + conf[i]*base;
                base = base*10;
            }
            return j;
        }

        void print(){
            for(int i = 0 ; i < 3; i++){
                for(int j= 0 ; j < v[i].size() ; j++){
                    cout<<"("<<v[i][j]<<","<<a[v[i][j]]<<")";
                }
                cout<<endl;
            }
        }
        bool valid(int i, int j){
            if(v[i].size() == 0)return false;
            if(v[j].size() == 0)return true;
            if(a[v[i][0]] > a[v[j][0]])return false;
            return true;
        }

        GameState move(int i, int j){
            int from = v[i][0];
            conf[from] = j;
            GameState nw(conf);
            conf[from] = i;
            return nw;
        }
};

bool dfs(GameState g, long long final){
    vis.insert(g.id());
    bool pos = false;
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j++){
            if(i == j)continue;
            if(!g.valid(i,j))continue;
            GameState to = g.move(i,j);
            if(vis.find(to.id())!= vis.end())continue;
            from[to.id()] = g.id();
            prev_move[to.id()] = make_pair(i,j);
            if(to.id() == final)pos = true;
            pos = pos | dfs(to, final);
        }
    }
    return pos;
}

int main(){
    // int a[3] ={1,2,3};
     GameState start(initialconfig);
     GameState final(finalconfig);
     cout<<dfs(start,final.id());
     long long cur = final.id();
     while(cur != start.id()){
        cout<<cur<<" "<<prev_move[cur].first<<" "<<prev_move[cur].second<<endl;
        cur = from[cur];
     } 
    // cout<<whowins(start);
}