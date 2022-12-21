#include <bits/stdc++.h>
using namespace std;



class JSON
{
    int i;
    string s;
    vector<int> vi;
    vector<string> vs;
    int type = 0;
    public:
        JSON(int d)
        {
            i = d; type = 1;
        }
        JSON(string d)
        {
            s = d; type = 2;
        }
        JSON(vector<int> d){
            vi = d; type = 3;
        }
        JSON(vector<string> d){
            vs = d; type = 4;
        }


        string stringify(){
            if(type == 1){
                return stringify_integer(i);
            }
            if(type == 2){
                return stringify_string(s);
            }
            if(type == 3){
                return stringify_vector_integer(vi);
            }
            if(type == 4){
                return stringify_vector_string(vs);
            }
            return "type not found";
        }

        string stringify_integer(int x){
            string c = "{" + to_string(x) + "}";
            return c;
        }

        string stringify_string(string x){
            string c = "{" + x + "}";
            return c;
        }
        
        string stringify_vector_string(vector<string> x){
            string c = "{";
            for(int i =0 ; i < x.size() - 1; i ++)
             c +=  (x[i] + ",");
            c += x[x.size() - 1];
            c += "}";
            return c;
        }

        string stringify_vector_integer(vector<int> x){
            string c = "{";
            for(int i =0 ; i < x.size() - 1; i ++)
             c +=  to_string(x[i]) + ",";
            c += to_string(x[x.size() - 1]);
            c += "}";
            return c;
        }
};

int main()
{
    string s ="ddd";
    vector<int> v (5,0);
    JSON s1(v);
    JSON s2(s);
    cout<< s1.stringify()<<endl;
    return 0;
}