We are given a function  which is unimodal on an interval . By unimodal function, we mean one of two behaviors of the function:

The function strictly increases first, reaches a maximum (at a single point or over an interval), and then strictly decreases.

The function strictly decreases first, reaches a minimum, and then strictly increases.

In this article, we will assume the first scenario. The second scenario is completely symmetrical to the first.

The task is to find the maximum of function  on the interval .

https://cp-algorithms.com/num_methods/ternary_search.html

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}


ternary_search can also be used to find a number in log 3 (n)

int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {
  
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
  
        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
  
        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1]) {
  
            // The key lies in between l and mid1
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
  
            // The key lies in between mid2 and r
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {
  
            // The key lies in between mid1 and mid2
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
  
    // Key not found
    return -1;
}






The function strictly decreases first, reaches a minimum, and then strictly increases.

while(r - l > 5){
	int m1 = l + (r - l)/3;
	int m2 = r - (r - l)/3;

	int cost1 = f(m1);
	int cost2 = f(m2);

	if(cost1 < cost2){
		r = m2;
	}else{
		l= m1;
	}

}

for(int  i = l ; i <= r; i++){
	ans = min(ans, f(i));
}

