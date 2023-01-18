class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      //return max sum from circular subarray.
      int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;
      for(auto i:nums){
          //using kadane algorithm OR delete the least element and calc the sum of others
          total_sum +=i;
          curr_sum1+=i;
          curr_sum2+=i;
          mxsum_subary= max(mxsum_subary, curr_sum1);
          if(curr_sum1<0) curr_sum1=0;
          minsum_subary=min(curr_sum2, minsum_subary);
          if(curr_sum2>0) curr_sum2=0;
        }
        return (total_sum==minsum_subary) ? mxsum_subary:max(mxsum_subary, total_sum-minsum_subary); 
    }
};
