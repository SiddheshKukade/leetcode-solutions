class Solution {
public:
    int binarySearchRecursive(vector<int>&arr, int k , int l , int r ){
      if (l> r) return -1 ; //wrong entry
      else {
          int mid = (int) (l + r) /2;
          if(arr[mid]==k) {
              return mid ;
          }
          else if (arr[mid] < k){
              return binarySearchRecursive(arr , k , mid+1, r);
          }
          else if (arr[mid] >k ){
              return binarySearchRecursive(arr , k , l, mid-1);
      }
     
      }
    return -1;
    }
		int search(vector<int>& nums, int target) {
		return binarySearchRecursive(nums, target, 0 , nums.size()-1 );
		// //Iteration Method 
		// int l= 0 ;
		// int r= nums.size()-1;
		// int mid=0;
		// if (nums[mid] == target) return mid; // if mid is the answer
		// while (l <= r) { 
		// mid = (l + r) / 2; // calculate the mid on every iteration
		// if(target > nums[mid]) { // if value is on the upper side
		// l = mid +1; // shift the left side to element next to mid 
		// }else if(target < nums[mid]) { // if on lower side
		// r = mid -1; // adjust mid to before it
		// }
		// }
		// return -1 ; // if element is not matched

    }
};
