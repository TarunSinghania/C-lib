#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long

 int a[MAX];
 ll dp[MAX][30];
ll q(int L, int R){
    int sum = 0;
    int d = R - L + 1; 
    for(int j = 29; j >= 0; j--){
        if((d>>j) & 1){
            sum = sum + dp[L][j];
            L = L + (1 << j);
        }
    }
    return sum;
}

int main(){


     int n;
     cin>>n;
     for(int i = 0 ; i < n ; i++){
         a[i] = i;
         dp[i][0] = i;
     }
     for(int j = 1 ; j < 20; j++){
         for(int i = 0 ; i < n ; i++){
                //we only fill dp[i][j] that is valid rest is left 0
            // while query we only use valid states 
                 if(i + (1<<(j-1)) > MAX) continue; 
                 dp[i][j] = dp[i][j-1] + dp[i + (1<<(j-1))][j-1];
         }
     }
     cout<<q(3,10)<<endl;
}