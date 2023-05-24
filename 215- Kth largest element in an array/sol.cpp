class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // TC o n log n
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];

        //TC O n

        //auto inserts all the element in max heap manner
        // MAX HEAP
        // priority_queue<int> pq(nums.begin(), nums.end());
        // int ans =0;
        // while(k--){
        //     ans = pq.top();
        //     pq.pop();
        // }
        // return ans;

        /// MIN HEAP
         priority_queue<int, vector<int> , greater<int>> pq;

        for(auto x: nums){
            pq.push(x);
            if(pq.size() > k){ // /if size more than k
                 pq.pop(); // remove the smallest from the grouo
                }
        }

        return pq.top(); /// returning the remaining kth largest from a group of kth largest numbers 




    }
};
