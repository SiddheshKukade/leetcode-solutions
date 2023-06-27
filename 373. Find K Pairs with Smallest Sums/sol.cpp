class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> resV;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int x: nums1){
            pq.push({x + nums2[0], 0});
        }
        while(k-- && !pq.empty()){
            int sum = pq.top().first;
            int pos = pq.top().second;
            resV.push_back({sum-nums2[pos],nums2[pos]});
            pq.pop();
            
            if(pos+1< nums2.size()){
                pq.push({sum - nums2[pos] + nums2[pos+1], pos+1});
            }
        }
        return resV;
    }
};
