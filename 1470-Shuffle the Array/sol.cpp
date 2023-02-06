class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        vector<int> second;

        for(int i =n; i<nums.size(); i++){
            second.push_back(nums[i]);
        }
        for(int i =0; i<n; i++){
                ans.push_back(nums[i]);
                ans.push_back(second[i]);
        }
        return ans;
    }
};
