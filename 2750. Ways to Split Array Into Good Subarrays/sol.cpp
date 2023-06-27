2750. Ways to Split Array Into Good Subarrays
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans =1, mod = 1000000007, count =0;
        int i=0; 
        while(i<nums.size() && nums[i] ==0) ++i;
        if(i>=nums.size() ) return 0; // all no are 1s
        while(i<nums.size()){
            if(nums[i] == 1){
                ans = (ans *(count +1))%mod;
                count =0;
            }
            else count++;
            i++;
        }
        return ans;
    }
};
