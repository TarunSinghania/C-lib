include <bits/stdc++.h>
 
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define ll long long
#define mkp make_pair 
#define MAX 100005
#define MAX_LOG 25
#define INF 10000000000000
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
#define prs(s) for(auto x : s){cout<<x.first<<"#"<<x.second<<" ";}cout<<endl;
int v,e;
vector<pair<int,int> > adj[MAX];
ll d[MAX];
bool vis[MAX];
void init(){
        fr(i,1,v+1)
            d[i]=INF,vis[i]=false;
}
 
void mst(int st=1){
    init();
    d[st]=0;
    set<pair<ll,int> > s;
    fr(i,1,v+1)
    s.insert(mkp(d[i],i));
    //prs(s);
    while(!s.empty())
    {
        int u = s.begin()->second;
        vis[u]=true;
       
        s.erase(s.begin());
        for(auto p : adj[u])
        {
                if(vis[p.first])continue;
                int v = p.first;
                int w = p.second;
                if(d[v] > w)
                        {
                            s.erase(mkp(d[v],v));
                            d[v]= w;
                            s.insert(mkp(d[v],v));
                        }
        }
    }
 
}
 
 
 
 
int main()
{
    cin>>v>>e;
    fr(i,0,e)
    {   
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb(mkp(y,w));
        adj[y].pb(mkp(x,w));
    }
    mst();
    ll ans = 0;
    //pr(d,v+1);
    fr(i,1,v+1)
    ans+=d[i];
    cout<<ans<<endl;
 
}                        