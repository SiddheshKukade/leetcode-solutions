class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1;
        int right=1;
        for(right =1; right<nums.size();right++){
            if(nums[right] !=nums[right-1]){ //if new element is found 
                //always comparing current with previous
                nums[left] = nums[right];  // insert to right pointer
                left ++;//increment left pointer
            }
        }
    return left;  // if no new element then return no as 1 by default
    }
};
