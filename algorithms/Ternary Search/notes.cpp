weakly unimodal function :

ternary search wont work 

1,0,(0),0,0,0,(0),0,-1,2
1,-1,0,(0),0,0,0,(0),0,2

we wont know what to do when m1 equals m2 and will have to recurse on all parts

sample solution with binary search can extend to ternary search as well 

int findMinimumVShaped(int[] arr) {
    return findMinimumVShaped(arr, 0, arr.length - 1);
  }

  int findMinimumVShaped(int[] arr, int start, int end) {
    while (end - start > 1) {
      int mid = start + (end - start) / 2;
      int midVal = arr[mid];
      boolean lessThanLeftNeighbor = midVal < arr[mid - 1];
      boolean lessThanRightNeighbor = midVal < arr[mid + 1];
      if (lessThanLeftNeighbor) {
        if (lessThanRightNeighbor) {
          // We found the minimum.
          return midVal;
        }
        // We are on the left side of the V. We need to look on the right side.
        start = mid + 1;
      } else if (lessThanRightNeighbor) {
        // We are on the right side of the V. We need to look on the left side.
        end = mid - 1;
      } else {
        // The midpoint is in the middle of a plateau. We don't know if we're on the left or
        // right side of the V. We need to search for a minimum on each side. If neither is a V,
        // they are both downward slants ending on the plateau, and the base case will cause both
        // to return the plateau value. If one of them is a V, that side will produce the final min.
        return Math.min(
            findMinimumVShaped(arr, start, mid - 1), findMinimumVShaped(arr, mid + 1, end));
      }

    }
    return Math.min(arr[start], arr[end]);
 }

int search(int l , int r){

while(r - l > 5){
	int m1 = l + (r - l)/3;
	int m2 = r - (r - l)/3;

	int cost1 = f(m1);
	int cost2 = f(m2);

	if(cost1 < cost2){
		r = m2;
	}else if (cost1 > cost2 ){
		l= m1;
	}else{
		return min(search(l,m1-1),search(m1,m2),search(m2+1,r));
	}

}

for(int  i = l ; i <= r; i++){
	ans = min(ans, f(i));
}

	return ans;
}
