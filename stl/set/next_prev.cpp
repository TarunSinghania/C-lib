#include <bits/stdc++.h> 
using namespace std;
//lower bound, upper bound, prev, next, ++, --

int main()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	auto it = s.lower_bound(1);
	cout<<*it<<endl;
    if(it == s.begin()){
	    cout<<"pointing to first"<<endl;    
	}
	//if you keep reduting iterator from begin it wont reduce
	it--;
	it--;
	cout<<*it<<endl;
	if(it == s.begin()){
	    cout<<*it<<endl;
	}
	it = s.lower_bound(2);
	//last element != end
	if(it == s.end()){
	    cout<<"end"<<*it<<endl;
	}
	cout<<*it<<endl;
	
	it = prev(it);
	it = next(it);
	cout<<"prev"<<*it<<endl;
	cout<<"next"<<*it<<endl;
    return 0;
}