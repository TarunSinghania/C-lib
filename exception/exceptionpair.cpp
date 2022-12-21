#include <bits/stdc++.h>
using namespace std;



int main()
{
   int x = -1;
 
   // Some code
   cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
        pair<int,int> e ={1,x};
         throw e;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (pair<int,int> y) {
         cout << "Exception Caught negtive number "<<y.first<<y.second<<endl;;
   }
 
   cout << "After catch (Will be executed) \n";
   return 0;
}