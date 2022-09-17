class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       //for every subarray just return the maximum  
        //non optimized solution O n*k
//         vector<int> ans;
//         for(int i=0 ; i<nums.size()-1; i++){
//             int maxi=nums[i];
//             for(int j=i; j<(i+k-1); j++){
//                 maxi= max(nums[j], maxi);
//             }
//                 ans.push_back(maxi);
//         }
//         return ans;
        //OPTIMIZED SOLUTION WITH NEXT GREATER ELEMENT
        // time On+ On
        deque<int> dq; // stores the index of arrays
        vector<int> ans;
        for(int i=0 ; i<nums.size(); i++){
        //removing the out of bound elements
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            //dq.front() returns the index of the current front element;
            
            //removing the elements lesser than the current elemetns 
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            //the finally push current element 
            dq.push_back(i); // pushing the indexs
            //// if we completed current window size then push the answer
            /// our front would always be having the greatest element
            if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
        return ans;
    }
};
