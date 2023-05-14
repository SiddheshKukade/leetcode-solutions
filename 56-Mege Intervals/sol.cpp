class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // TC nlogn + on
        // SC on
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0) return mergedIntervals;

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; // holds the current higest 
        // range interval and tries to merge the other smaller ones in itself.

        for(auto it:intervals){
            if(it[0]<= tempInterval[1]){
                tempInterval[1] = max(it[1] , tempInterval[1]);
            }else {
                // if greater than tempInterval is found
                mergedIntervals.push_back(tempInterval); //mereged or not put in ans;
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval); //mereged or not put in ans;
        return mergedIntervals;
    }
};
