class Solution {
public:
 

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int previous = 0;
        int n = intervals.size();
        int ans=0;
        for(int current = 1; current<n; current++){
            if(intervals[current][0] < intervals[previous][1]){
                ans++;
                if(intervals[current][1] <=intervals[previous][1]){
                    //delete the bigger interval
                    previous = current; 
                }
            }else{
                previous=current;
            }
        }
        return ans;
    }
};