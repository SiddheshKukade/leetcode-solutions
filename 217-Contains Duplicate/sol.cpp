class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {\
        //Brute force Approach time On2 space On
        // for(int i=0; i<nums.size();i++){
        //     for(int j=i+1; j<nums.size();j++){
        //         if(nums[i]== nums[j]) return true;
        //     }
        // }
        
        
        // sort(nums.begin() , nums.end()); //OnLogN sp On
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i] == nums[i+1]) return true;
        // }
        // return false;
        
        //USING MAPS time On sp On
        // unordered_map<int,int>m;
        // for(auto a :nums) m[a]++;
        // for(auto a:m){if(a.second>1) return true;} 
        // return false;      
        
        //USING SETS time On sp On
        unordered_set<int> s;
        for(auto a:nums) s.insert(a); /// set will only accpet unique values
        if(nums.size()==s.size()) return false;
        return true;
    }
};
