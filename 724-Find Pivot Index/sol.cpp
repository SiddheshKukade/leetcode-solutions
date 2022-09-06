class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      ///first we will calculate entire sum of array to get the right sum automatically
        ///then we will compare right sum with each element 
        int sum=0;
      for(int i=0;i<nums.size();i++){
          sum+=nums[i];
      }
        int lsum=0, rsum=sum;
        for(int i=0;i<nums.size();i++){
            rsum = rsum - nums[i];
          if(lsum==rsum){
              return i;
          }
            lsum+=nums[i];
      }
        return -1;
    }
};
