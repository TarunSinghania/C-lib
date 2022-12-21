// C++ program to illustrate the
// Kahan summation algorithm
#include <bits/stdc++.h>
using namespace std;

// Function to implement the Kahan
// summation algorithm
double kahanSum(vector<double> &fa)
{
	double sum = 0.0;
	double c = 0.0;
	for(double f : fa)
	{
		//we keep adding the value of f not added to sum to y, because sum is much greater than f, when y gets big enough it is then added to y
		double y = f - c;
		double t = sum + y;
		c = (t - sum) - y;
		sum = t;
	}
	return sum;
}
//more easy to understand

double sum = 0;
double c = 0;

for(int i =0 ; i < n ; i++){
    double left = a[i] + c;
    double new_sum = sum + left;
    double still_left = left - (new_sum - sum)
    left = still_left;
}


double sum(vector<double> &fa)
{
	double sum = 0.0;

	for(double f : fa)
	{
		sum = sum + f;
	}
	return sum;
}

// Driver code
int main()
{
	vector<double> no(10);
	for(int i = 0; i < 10; i++)
	{
		no[i] = 0.1;
	}

	// Comparing the results
	cout << setprecision(16);
	cout << "Normal sum: " << sum(no) << " \n";
	cout << "Kahan sum: " << kahanSum(no);	
}

