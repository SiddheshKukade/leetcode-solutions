class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int n:nums){
            // 4/5 = 4 +5 = 9/5 = 4 again
            sum = ((sum+n)%k+k)%k;
            mp[sum]++;
            if(mp[sum]>1){
                ans+=mp[sum]-1;
            }
        }
        return ans;
    }
};
