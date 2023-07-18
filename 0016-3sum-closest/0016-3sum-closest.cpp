class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int nearsum = nums[0] + nums[1]+nums[2];
        int currsum=0;
        int n = nums.size();
        int s =0, e=n-1;
        for(int i=0; i<n-1; i++){
            s = i+1;
            e = n-1;
            while(s<e){
                currsum = nums[s] + nums[e] + nums[i];
                if(abs(currsum - target) < abs(nearsum - target)){
                    nearsum = currsum;
                }
                if(currsum > target){
                    e--;
                }else{ s++;}
            }
        }
        return nearsum;
    }
};