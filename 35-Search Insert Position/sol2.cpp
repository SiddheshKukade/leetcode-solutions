class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if(target <= nums[0]){
        //     return 0;
        // }
        for(int i=0; i<nums.size();i++){
            // cout<<i;
            // if(nums[i] == target){
            //     return i;
            // }
            // if(target> nums[i] && target < nums[i+1] && target != nums[i+1] && target != nums[i] ){
            //     return i+1;
            // }
            if(target == nums[i] || target< nums[i]) return i;
        }
        return nums.size();
    }
};
