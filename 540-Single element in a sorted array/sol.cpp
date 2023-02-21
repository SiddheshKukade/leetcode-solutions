class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //brute force: xor the next with gap of 2nos  if not zero then it is single number.
         int low =0, high = nums.size() -2;
         while(low <= high){
             int mid = (low+ high) >>1;
          
             if(nums[mid] == nums[mid^1]){
                    // performing xor operation here which converts even -> odd
             // and odd-> prev even no.
            //  LEFT half
            low = mid+1;
             }else{
                 high = mid -1;
             }
         }
            return nums[low];
    }
};
