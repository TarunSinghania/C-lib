#include<bits/stdc++.h>
using namespace std;
#define ll long long

int bias = 127;


string base2(char c[], int l){
    ll num = 0;
    ll base =1;
    for(int i = l - 1; i >= 0 ; i--){
        num = num + (c[i]-'0')*base;
        base = base * 10;
    }
    int first = -1; int x[61];
    for(int i = 60 ; i >= 0; i--)x[i] = 0;
    for(int i = 60; i>= 0 ;i--){
           x[i] = (((1ll<<i) &  num) > 0 ? 1 : 0 ) ;
           if(first == -1 && x[i] > 0) first = i;
    }

    string s = "0";
    if(first == -1)return s;
    string t;
    for(int i = first; i>= 0 ; i--){
            char z = x[i] + '0';
            t+= string(1,z);
    }
    return t;
}

string base2(int num){
     int first = -1; int x[61];
    for(int i = 60 ; i >= 0; i--)x[i] = 0;
    for(int i = 60; i>= 0 ;i--){
           x[i] = (((1ll<<i) &  num) > 0 ? 1 : 0 ) ;
           if(first == -1 && x[i] > 0) first = i;
    }

    string s = "0";
    if(first == -1)return s;
    string t;
    for(int i = first; i>= 0 ; i--){
            char z = x[i] + '0';
            t+= string(1,z);
    }
    return t;
}

//https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms
string decimalbase2(char c[], int l){
    ll num = 0;
    ll base =1;
    for(int i = l - 1; i >= 0 ; i--){
        num = num + (c[i]-'0')*base;
        base = base * 10;
    }
    string ans;

    if(num == 0)return ans = "0";
    while(num > 0 && ans.length() < 61){
        //remove trailing zeroes from input
        while(num > 0 && num%10 ==0)
            num = num/10;

        ll temp = num;
        int digits = 0, ndigits = 0;;
        while(temp > 0){
            temp = temp/10;
            digits++;
        }
        num = num + num;
        temp = num;
        while(temp > 0){
            temp = temp/10;
            ndigits++;
        }
        if(ndigits == digits){
            ans += '0';
            continue;
        }
        ans += '1';
        ll div = 1;
        for(int i = 1 ; i <= digits; i++){
            div = div*10;
        }
        num = num%(div);
        //remove any trailing zeroes
        while(num > 0 && num%10 ==0)
            num = num/10;
    }
    return ans;

}

//How computers covert ? A compuer only knows 0 and 1 
//shows how we loose precisssion as we input numbers 
string IEEE754floatingSingle(char num[], int l, int sign){
    //assuming it fits under range

    //Input is a stream of characters

    // we have integer, long long datatype implemented 
    // and operations such as add, substraction and multiplication are implemented on binary values
    string _sign ="0", exp, mantissa(23,'0');
    
    if(sign)
        _sign = "1";
    
    char prefix[l], suffix[l];
    int pl = 0, sl = 0;
    for(int i = 0 ; i < l ; i++){
        prefix[i] = '0';
        suffix[i] = '0';
    }
    //the range is 
    bool swtch = false;
    for(int i = 0 ; i < l ; i++){
        if(num[i]=='.'){
            swtch = true; continue;
        }
        if(!swtch){
            prefix[pl] = num[i],pl++;
        }
        else
            suffix[sl] = num[i],sl++;
    }
    //we now have decimal representations of prefix and suffix point digit 
    // we have to concat base 2 representation for both prefix and suffix parts 
    //in mantissa we store 23 digits so we will select the first 23 bits of this concatenation


    //here we convert prefix into binary representation by converting prefix into long long 
    //and then converting to binary
    //the range of single precission falls under long long range
    //for double precission we need extra implementation : we will only select digits from left to right untill we are less than long long value, after which the remaing digits can be seen as 10^numberofdigits remaining and will be added in 

    string pbase2 = base2(prefix,pl);



    //conversion of the part after . 
    //0.625 in terms of 2^-1  + 2^-2 + 2^3
    //upto 60 digits support for this
    string sbase2 = decimalbase2(suffix,sl);




    //combining both and calculating exponent
    if(pbase2.length() == 1 && pbase2[0] == '0'){
        //left side is 0, todo
        //exp is negative check number of 0s before first one
    
    }else if(sbase2.length() == 1 && sbase2[0] == '0'){
        //right side is 0, todo

    }else{
        //both side have some value
        exp = base2(bias + pbase2.length() - 1);
        
        string concat = pbase2 + sbase2;
        for(int i = 1 ; i < concat.length() && i - 1 < mantissa.length() ; i++){
            mantissa[i-1]  = concat[i];
        }
    }

    string ans;
    ans = _sign + exp + mantissa;
    return ans;
}

//0.1 + 0.2 not equals to 0.3 precission error
//compensated sum when summing - kahan 

int32_t main()
{
    char x[8] = {'9','3','.','1','2','2','0','1'};
    cout<<IEEE754floatingSingle(x,6,0);
}   

