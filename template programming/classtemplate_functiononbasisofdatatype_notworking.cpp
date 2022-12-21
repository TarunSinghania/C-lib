#include <bits/stdc++.h>
using namespace std;

//incomplete doesnt work -> c++ doesnt let us compile

template <typename T> class JSON
{
    T data;
    public:
        JSON(T d)
        {
            data = d;
        }

        string stringify(){
            if(std::is_same<T, std::vector<int>>::value){
                return "x";
            }
            if(is_same<T, std::string>::value){
                stringify_string(data);
            }
            return "e";
        }

        string stringify_string(T d){
            
            return d;
        }
        
        
};

int main()
{
    string s ="ddd";
    vector<int> v (2,0);
    JSON<vector<int>> s1(v);
    JSON<int> s2(23);
    cout<<s1.stringify();
    return 0;
}