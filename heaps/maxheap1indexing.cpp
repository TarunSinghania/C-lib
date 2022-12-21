#include<bits/stdc++.h>
using namespace std;

class heap{
public:
    int *a;
    int cnt;
    int sz;
    int type;
    //0 for min 1 for MAX
    heap(int cap = 5, int t = 1){
        sz = cap;
        type = t;
        cnt = 0;
        a  = new int[cap+1];
        for(int i = 1 ; i <= cap; i++){
            a[i] = ( (type == 1) ? INT_MIN: INT_MAX );
        }
    }   
    bool better(int x, int y){
        //is x better than y
        return ((type == 1) ? x > y : x < y );
    }
    int top(){
        if(cnt == 0)return ( (type == 1) ? INT_MIN: INT_MAX );
        return a[1];
    }
    void percolatedown(int n){
        int best = n;
        if( 2*n <= cnt && better(a[2*n],a[best]))
            best = 2*n;
        if( 2*n + 1 <= cnt && better(a[2*n + 1],a[best]))
             best = 2*n + 1;
        if(best != n){
            swap(a[best], a[n]);
            percolatedown(best);
        }
    }
    void resize(int n){
        int *x = new int[n+1];
        for(int i = 1; i <= sz ; i++)
            x[i] = a[i];
        for(int i = sz + 1; i <= n ; i++)
            x[i] = ( (type == 1) ? INT_MIN: INT_MAX );
        delete []a;
        a = x;
        sz = n;
    }

    void buildheap(int c[], int n){
        if(n > sz){
            resize(n);
        }
        for(int i = 1; i <= n ; i++)
            a[i] = c[i-1];
        
        for(int i = n + 1; i <= sz ; i++)
            a[i] = ( (type == 1) ? INT_MIN: INT_MAX );


         cnt = n;
        //first non leaf node to top
         for(int z = n/2 ; z >= 1 ; z--){
            percolatedown(z);
         }
    }

    void pop(){
        if(cnt == 0)return;
        a[1] = a[cnt];
        a[cnt] = ( (type == 1) ? INT_MIN: INT_MAX );
        cnt--;
        percolatedown(1);
    }
    void insert(int x){

        if(cnt + 1 > sz){
            resize(sz<<1);
        }

        cnt++;
        a[cnt] = x;

        int i = cnt;
        while(i/2>=1 && better(a[i],a[i/2])){
            swap(a[i],a[i/2]);
            i = i/2;
        }
    }
    void print(){
        for(int i = 1; i <= cnt ; i++){    
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void raw(){
        for(int i = 1; i <= sz ; i++){    
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    bool empty(){
        return (cnt == 0);
    }

};



int main(){
    
    int a[10] = {1,3,2,4,6,7,9,8,10,5};
    heap h;
    h.buildheap(a,10);
    h.insert(20);
    h.insert(30);
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }

    return 0;
}