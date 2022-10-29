class Solution {
public:
    void findCombination(int ind , int target ,  vector<int> &arr , vector<vector<int>> &ans , vector<int> &ds){
        if(ind == arr.size()){
            if(target ==0){
                ans.push_back(ds);
            }
            return ;
        }
        //pick 
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind, target- arr[ind] , arr, ans, ds); // remove the current after pick
            ds.pop_back(); // pop back that element after it is returned 
            // returned only when the combination is found
        }
        //not pick 
        //because the index is larger than current target so not pick and move to the next index of the given array
        findCombination(ind+1, target, arr, ans, ds);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // TC - 2^t * K  (2^t for pick and non pick and K for data structure )
        //SC - Cannot predict depends on the number of combinations 
        // hypothetucal SC K * X (X is no of combinations ) 
        vector<vector<int>> ans;
        vector<int> ds ;
        findCombination(0 , target, candidates , ans, ds);
        return ans;        
    }
};
