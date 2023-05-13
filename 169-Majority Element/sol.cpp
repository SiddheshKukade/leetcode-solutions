class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
            if(mp[num] >nums.size()/2) return num;
        }
return -1;
    }
};
//  ON N
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*       unordered_map<int,int> mp;
                for(auto num: nums){
                    mp[num]++;
                    if(mp[num] >nums.size()/2) return num;
                }
           
        return -1; */
    // Approach 2 sort
    /*
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
    untime25 ms
 */

            // Approach 3
            // Using candidates and votes
            int c=0,v=0;
            for(auto n:nums){
                if(v==0){
                    c=n;
                }
                if(c==n) v--;
                else v++;
            }
            return c;
    }
};
