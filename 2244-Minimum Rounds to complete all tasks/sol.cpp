class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        map<int , int> m;
        for(int i=0 ; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int mini= 0;
        for(auto it : m ){
            if(it.second ==1 ) return -1;
            int cnt =0;

            while(it.second>3)
            it.second-=3, cnt++;

            if(it.second)
            cnt++;

            mini += cnt;
        }
        return mini;
    }
};
