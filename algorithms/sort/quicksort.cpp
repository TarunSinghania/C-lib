#include<bits/stdc++.h>
using namespace std;

int a[10] = {1,3,2,4,6,7,9,8,10,5};


void pr(){
    for(int i = 0 ; i < 10 ; i++){
        cout<<a[i];
    }
    cout<<endl;
}

int median(int a[], int l , int r){
    int m = l + (r - l)/2;
    if((a[m] <= a[l] && a[l] <= a[r]) || (a[r] <= a[l] && a[l]<= a[m])) return l;
    if((a[m] <= a[r] && a[r] <= a[l]) || (a[l] <= a[r] && a[r]<= a[m])) return r;
//    if(a[l] <= a[m] <= a[r] || a[r] <= a[m] <= a[l]) return m;
    return m;
}   


int partition(int a[], int l, int r){
    int p = median(a, l , r);
    swap(a[p],a[r]);
    int L = l, R = r -1;
    while(L < R){
            while(a[L] <= a[r])L++;
            while(a[R] > a[r])R--;
            if(L < R)
             swap(a[L], a[R]);
    }
    swap(a[L],a[r]);
    return L;
}


void quicksort(int a[], int l, int r){
    if(l >= r)return;
    int p = partition(a, l , r);
    quicksort(a, l , p - 1);
    quicksort(a, p + 1, r);

}

int main(){
//int a[10] = {1,3,2,4,6,7,9,8,10,5};
    
quicksort(a,0,9);
pr();
    return 0;
}