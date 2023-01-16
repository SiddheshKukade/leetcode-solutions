Siddhesh Bhupendra Kuakde
Siddhesh Bhupendra Kuakde
Jan 16, 2023 23:44
C++
Runtime16 ms
Beats
83.48%
Memory17.1 MB
Beats
45.20%
Click to check the distribution chart
Notes
Related Tags
0/5

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          int n = intervals.size();
          int i=0; 
          vector<vector<int>> res;
          while(i<n && intervals[i][1]<newInterval[0]){ //if [1,2]'s 2 is smaller than [4,8]'s 4
              res.push_back(intervals[i]); //add to ans
              i++; // check for next interval
          }
          while(i<n && newInterval[1]>=intervals[i][0]){ // if [4,8]'s 8 is larger than [1,2]'s 1
          // merging the ending points and starting points
              newInterval[0] = min(newInterval[0], intervals[i][0]);
              newInterval[1] = max(newInterval[1], intervals[i][1]);
              i++;
          }
          res.push_back(newInterval);
          while(i<n){
              res.push_back(intervals[i]);
              i++;
          }
          return res;
    }
};
