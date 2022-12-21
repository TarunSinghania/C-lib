#include <bits/stdc++.h> 
using namespace std;
//Kmp when we see a mismatch at index j 
//we select the longest proper prefix which is also a suffix 
//why we choose longest ? why will it always give answer
//when we choose longest we move the pointer minimum steps ahead and if it fails then we are not skipping the one which can have the answer

void lpscalc(string s, vector<int> &pi) {
        int n = s.size();
        pi.resize(n);
        for(int i = 1; i < n; i++) 
        {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }  
}

void KMP(string text, string pattern){
    vector<int> lps;
    lpscalc(pattern, lps);
    for(auto x : lps){
        cout<<x;
    }
    cout<<endl;
    int N = text.length();
    int M = pattern.length();
    
   // string[i] , pattern[j];
    int i = 0, j = 0;

    while(i < N){
        if(pattern[j] == text[i]){
            i++; j++;
            if(j == M){
                cout<<"pattern"<<i-j<<endl;
                j = lps[j - 1];
                continue;
            }
        }else if(text[i] != pattern[j]){
            if(j != 0){
               j = lps[j - 1];
            }else{
                i = i + 1;
            }
        }
    }
}

//kmp2 is not tested
void KMP2(string text, string pattern){
    vector<int> lps;
    lpscalc(pattern, lps);
    for(auto x : lps){
        cout<<x;
    }
    cout<<endl;
    int N = text.length();
    int M = pattern.length();
    
   // string[i] , pattern[j];
    int i = 0, j = 0;
    for(int i = 0 ; i < N ;){
        if(pattern[j] == text[i]){
            i++; j++;
            if(j == M){
                cout<<"pattern"<<i-j<<endl;
                j = lps[j - 1];
                continue;// check if  needed 
            }
        }else if(text[i] != pattern[j]){
            j =lps[j-1];
            while(j > 0 && pattern[j] != text[i]){
               j = lps[j - 1];
            }
            if(pattern[j] == text[i]){
                j = j + 1;
            }
            i++;
        }
    }
}


int32_t main(){

  KMP2("taruntarntaruntaruna", "tarun");
    //KMP("aaaaaaaaaaa","abcabsbsba");
    //cbcbbcbbcbcbcbbcbcbbcbcccbcbbcb
  //  KMP("")
    return 0;
}