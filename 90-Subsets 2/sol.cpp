class Solution {
public:
    void findSubset(int ind , vector<int> nums , vector<int> &ds , vector<vector<int>> &ans){
        ans.push_back(ds); // insert the current ds
        for(int i=ind ; i< nums.size(); i++){ // from current index to the end
            if(i != ind && nums[i] == nums[i -1]) continue; // makes sure that elements are added only once in the list 
            ds.push_back(nums[i]); // pick the index and put it to the ds
            findSubset(i+1 , nums, ds , ans); // continue with the next subset
            ds.pop_back(); // remove after that function call 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // here the condition is that subsets should not have repeating elements
         vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin() ,nums.end());
        findSubset(0 , nums , ds , ans); // calling the function starting with the 0th index
        return ans;
    }
};
