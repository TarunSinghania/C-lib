    #include <bits/stdc++.h> 
    using namespace std;
    #define fr(i,a,b) for(int i=a;i<b;i++)
    #define pb push_back
    #define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
    #define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
    #define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
    #define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
    #define endl '\n'
    #define MOD 1000000007
    #define INF 1000000000
    #define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
    #define MAX 400005
    #define all(x) x.begin(),x.end()
    #define mkp make_pair 
    #define ll long long
    #define f first
    #define s second
    vector<pair<int,int> > adj[MAX];
    int v,e;
    int w[MAX];
    int done[MAX];
    //lazy version
    class cmp
    {
        public:
        bool operator()(pair<int,int> a , pair<int,int> b)
        {
              if(a.f == b.f)
            return a.s > b.s;
                else
            return a.f > b.f;
        }
    };
     
    void mst(int s){
        fr(i,1,v+1){
            w[i]= INF;
            done[i]=false;
        }
        priority_queue<pair<int,int>, vector<pair<int,int> > , cmp > q;
        q.push({0,s});
     
        while(!q.empty()){
            int node = q.top().s;
            int weight = q.top().f;
            q.pop();
            if(done[node])continue;
            done[node] = true;
            w[node] = weight;
            for(auto x: adj[node]){
                if(!done[x.f]){
                    q.push({x.s,x.f});
                }
            }
        }
    }
    int main(){
        cin>>v;
        cin>>e;
        fr(i,0,e){
            int x,y,z;
            cin>>x>>y>>z;
            adj[x].pb({y,z});
            adj[y].pb({x,z});
        }   
        mst(1);
        
        ll ans = 0;
        fr(i,1,v+1){
            ans = ans + w[i];
        }
        cout<<ans<<endl;
        return 0;
    } 