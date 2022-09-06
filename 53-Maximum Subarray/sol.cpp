class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KADANE ALGORITHM
        //CARRAY A ALGORITHM SUM AS LONG AS IT GIVES POSITIVE SUM
        int sum =0 ; int maximum=INT_MIN;
        for(auto it: nums){
            sum+=it;
            maximum = max(maximum,sum);
            if(sum < 0) sum=0;
        }
        return maximum;
    }
};
