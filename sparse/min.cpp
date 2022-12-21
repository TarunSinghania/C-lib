#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long

int a[MAX];
int dp[MAX][30];
int lg[MAX];
int q(int L, int R){
    int j = lg[R -L + 1];
    return min(dp[L][j], dp[R - (1<<j) + 1][j]);
}


int main(){


     int n;
     n = 1000;
     lg[1] = 0;
     for(int i = 0 ; i < n ; i++){
         a[i] = i;
         dp[i][0] = i;
         //divide by is rightshifting by 1
         if(i > 1)
         lg[i] = lg[i/2]  + 1;

     }
     for(int j = 1 ; j < 20; j++){
         for(int i = 0 ; i < n ; i++){
            //we only fill dp[i][j] that is valid rest is left 0
            // while query we only use valid states 
            if(i + (1<<(j-1)) > MAX) continue; 
            dp[i][j] = min(dp[i][j-1],dp[i + (1<<(j-1))][j-1]);
         }
     }
     cout<<q(2,17)<<endl;
}