
void initialize( int Arr[ ], int size[ ],int N)
{
        for(int i = 0;i<N;i++)
        {
    Arr[ i ] = i ;
    size[ i ] = 1;
    }
}




     //finding root of an element
  int root(int Arr[ ],int i)
    {
        while(Arr[ i ] != i)           //chase parent of current element until it reaches root
        {
         i = Arr[ i ];
        }
        return (int)i;
    }


 bool find(int A, int B,int Arr[])
    {
        if( root(Arr,A) == root(Arr,B) )       //if A and B have the same root, it means that they are connected.
        return true;
        else
        return false;
    }


  void weighted_union(int Arr[ ],int size[ ],int A,int B)
    {
        int root_A = root(Arr,A);
        int root_B = root(Arr,B);
    
      //cout<<root_A<<"--"<<root_B<<endl;
      if(root_A == root_B)
        return;

    if(size[root_A] < size[root_B ])
        {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
        else
        {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }

    }

The video above presents a more visual explanation. Here's an optional mathematical explanation why the maximum height is log2N.
Imagine any element x in tree T1.
The depth of x increases by 1 only when T1is placed below another tree T2. 
When that happens, the size of the resulting tree will be at least double the size of T1. because size(T2)≥size(T1). The tree with x can double at most log2N times until we've reached a total of N items (2^log(base2)N=N). So we can double up to log(base2)N times and each time, our tree adds a level.


 

