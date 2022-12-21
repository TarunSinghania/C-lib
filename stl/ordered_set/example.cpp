#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void myerase(ordered_multiset &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than 
    auto it = t.find_by_order(rank);
    t.erase(it);
}

int main() {
    ordered_multiset ms;
    ordered_set s;
    vector<int> v{1, 1, 2, 2, 3, 4, 5, 6, 6};

    for(int i : v) ms.insert(i), s.insert(i);

    cout << "Ordered set:"<<endl;
    for(auto x : s) cout << x << ' '; cout << '\n';
    cout << "Lower bound of 2: " << *s.lower_bound(2) << '\n';
    cout << "Upper bound of 2: " << *s.upper_bound(2) << '\n';
    cout << "order_of_key of 2: " << s.order_of_key(2)<<endl;
    cout << "find_by_order of 3:" << *s.find_by_order(3)<<endl;

    for(auto x : ms) cout << x << ' '; cout << '\n';
    cout << "Ordered Multiset:"<<endl;
    for(auto x : ms) cout << x << ' '; cout << '\n';
    cout << "Lower bound of 2: " << *ms.lower_bound(2) << '\n';
    cout << "Upper bound of 2: " << *ms.upper_bound(2) << '\n';
    cout << "order_of_key of 2: " << ms.order_of_key(2)<<endl;
    cout << "find_by_order of 3:" << *ms.find_by_order(3)<<endl;
    

    cout<<endl;

    cout<<"erase one 2"<<endl;
    myerase(ms,2);
    s.erase(2);
 
    cout << "Ordered set: "<<endl;
    for(auto x : s) cout << x << ' '; cout << '\n';

    cout << "Ordered Multiset:"<<endl;
    for(auto x : ms) cout << x << ' '; cout << '\n';



    return 0;
}

//indexing by 0 - order_of_key returns first observed position
//find_by_order returns ith element (indexing 0)
//lower bound and upper bound work reverse in multiset vs set as operator less changes to less equal
//normal erase doesnt work on multiset ordered set

