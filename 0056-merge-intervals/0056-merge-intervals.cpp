class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=0; i<n; i++){
                if(ans.back()[1]>=intervals[i][0])
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                else ans.push_back(intervals[i]);
        }
        return ans;
    }
};