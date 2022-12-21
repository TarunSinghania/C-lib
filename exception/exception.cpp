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
         throw 500;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int y) {
     if(y == 500)
         cout << "Exception Caught negtive number "<<x<<endl;;
   }
 
   cout << "After catch (Will be executed) \n";
   return 0;
}