//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/lis-revisted-0b3ed24b/?
#include<bits/stdc++.h>
using namespace std;

vector<int> LIS (int N, vector<int> v) {
   // Write your code here
   int minvalforl[(int)v.size() + 1];
      for(int i = 0 ; i < (int)v.size() + 1; i++){
         minvalforl[i] = INT_MAX;
      }
   minvalforl[0] = 0;
   minvalforl[1] = v[0];

    //stores longest increasing sequence ending at i
   vector<int> lis((int)v.size());
   lis[0] = 1;
   for(int i = 1; i < (int)v.size() ; i++){
      int l = 0; int r  = v.size();
      while(l < r){
            int m = l + (r - l + 1) /2;
            if(minvalforl[m] <= v[i])
                l = m;
            else
                r = m - 1;
      }
      cout<<endl;
      lis[i] = l + 1;
      minvalforl[l+1] = min(minvalforl[l+1], v[i]);
      // for(int i = 0 ; i <= v.size(); i++){
      //    cout<<minvalforl[i]<<",";
      // }
   }
 
   return lis;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> Arr(N);
    for(int i_Arr = 0; i_Arr < N; i_Arr++)
    {
    	cin >> Arr[i_Arr];
    }

    vector<int> out_;
    out_ = LIS(N, Arr);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}