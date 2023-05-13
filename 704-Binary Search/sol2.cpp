class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      if(n ==1) return nums[0] == target ? 0 : -1;
      int l=0, r=n-1;
      int m ;
      while(l<=r){
          m = (l+r)/2; //0 // l =1, r =1, m 2/2=1
          if(nums[m] == target){
              return m;
          } else if(nums[m] < target){
              l = m+1; // L = 0+1
              cout<<'g';
              
          }else  if(nums[m] > target){  r = m-1; } 
      }
      return -1;
    }
};
