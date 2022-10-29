class Solution {
public:
    void recurPermute(vector<int> &ds , vector<int> &nums , vector<vector<int>> & ans, int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(!freq[i]){ /// only if the freq is zero
                ds.push_back(nums[i]);
                freq[i] = 1; 
                recurPermute(ds, nums , ans , freq);
                freq[i] = 0 ; 
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
     //solving with the recursion  approach  
        // TC  =>  n! *  n ;
        // SC => o (n) + o(n ) // one for ans and other for ds  
        vector<vector<int>> ans;
        vector<int>ds;
        int n = nums.size();
        int freq[100] = {0} ; // initalized all to zero 
        for(int i= 0 ; i<nums.size(); i++) freq[i] =0 ; // another way to do it  
        recurPermute( ds, nums , ans , freq) ;
        return ans;
    }
};
