#include <bits/stdc++.h>
#include <chrono> 
using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now(); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false); 

    //0(n) operation
    string s(100, 'x');

    string s2, s3;
    
    //o(n^n) operation
    
    //for(int i = 1 ; i <= 1000000 ;i++){
    //     s2 = s2 +  'x';
    // }
    //took 15.85 seconds
    // creates a new copy everytime;


    //o(nlogn) 
    
    for(int i = 1 ; i <= 1000000 ;i++){
        s2 += 'x';
    }
    //took 0.008914
    // string are by default acting like vector, 
    //they have remaining space based on nearest 2^ith integer
    //then they resize based to twice 
    // += keeps current string in place and adss

    //o(nlogn)
    for (int i = 0; i < 1000000; ++i) {
      s3 = std::move(s3) + "xy";
    }
    //moves (same as +=)

    //to observe_behaviour  
  
    // string s2;
    // for(int i = 1 ; i <= 100 ;i++){
    //      s2 = s2 + 'x';
    //      cout<<" "<<s2.size()<<" "<<s2.capacity()<<&s2<<endl;
    //  }
    // for(int i = 1 ; i <= 100 ;i++){
    //      s2 += 'x';
    //      cout<<" "<<s2.size()<<" "<<s2.capacity()<<&s2<<endl;
    // }

    auto end = chrono::high_resolution_clock::now(); 
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
    time_taken *= 1e-9; 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 

}