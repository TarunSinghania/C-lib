#include<bits/stdc++.h>
using namespace std;
  #define ll long long
  #define fr(i,a,b) for(int i =a ; i < b; i++)
  #define frj(j,a,b) for(int j =a ; j < b; j++)
  #define fre(i,a,b) for(int i =a ; i <= b; i++)
  #define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

  #define mkp make_pair 
  #define pb push_back
  #define pii pair<int,int>
  #define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
  #define c(a,b) cout<<a<<"--"<<b<<endl;
  #define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
  #define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
  #define pp(a) cout<<a.first<<" "<<a.second<<endl;
  //sum array
  #define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
  #define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
  s[i]=s[i-1]+a[i];}

  #define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
  #define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;
  #define all(x)           x.begin(), x.end()

  constexpr auto PI  = 3.14159265358979323846L;
  constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
  constexpr auto eps = 1e-6;
  constexpr auto mod = 1000000007;


  #define MOD 1000000007
  #define maxv 200005
  #define MAXN 1000001


 int lis(vector<int> v)
{
  int n = v.size();

  vector<int> ml(n+1,INT_MAX);
  ml[0]=INT_MIN;
  ml[1]=v[0];
  int mx=1;
  //what is the minimum number in the array,
  //such that an increasing subsequence of length i terminates at
  fr(i,1,n)
  {
    //prv(ml);
    mx =1;
    int l =0;
    int r =n;

  
   // cout<<v[i]<<endl;
    while(l<r)
    {
      //cout<<l<<" "<<r<<endl;

      int m = (l+r)/2;
      if (ml[m]<v[i])
      { 
        l=m+1;
      }
      else 
        r=m;
    }
    // cout<<l<<"@"<<r<<"%"<<v[i]<<endl;
      //ml[l]=v[i];

      ml[l]=min(ml[l],v[i]);

  }
   //prv(ml);

  fr(i,1,n+1)
      if(ml[i]!=INT_MAX)
        mx=i;


    return mx;
}
int main()
{

int t,n,x;
cin>>t;
while(t--)
{
cin>>n;
vector<int> v;
fr(i,0,n)
cin>>x,v.pb(x);
cout<<lis(v)<<endl;
}


  return 0;
}

int lengthOfLIS(vector<int>& v) {
    //for each element i in v we have to see the max length
    //at every step for having an array of length i we know the minimum number 
    //this is always increasing in nature

    //if the condition was longest non decreasing subsequnce 
    //weakly monotonically increasing then we can also use binary search

        
    int minvalforl[v.size() + 1];
    for(int i = 0 ; i < v.size() + 1; i++){
        minvalforl[i] = INT_MAX;
    }
    minvalforl[0] = 0;
    minvalforl[1] = v[0];

    //stores longest increasing sequence ending at i
    int lis[v.size()];
    lis[0] = 1;
    for(int i = 1; i < v.size() ; i++){
        int l = 0; int r  = v.size();
        while(l < r){
            int m = l + (r - l + 1) /2;
            if(minvalforl[m] < v[i])
                l = m;
            else
                r = m - 1;
        }

        lis[i] = l +1;
        minvalforl[l+1] = min(minvalforl[l+1], v[i]);
    }
    int ans = 1;
    for(int i =0 ;i < v.size() ;i++){
   
        ans = max(ans, lis[i]);
    }    
    return ans;   
    
}
