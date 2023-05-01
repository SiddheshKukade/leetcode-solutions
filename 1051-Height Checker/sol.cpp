class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v1 = heights;
        sort(heights.begin(), heights.end());
        int count =0;
        for(int i=0; i<heights.size();i++){
            if(v1[i] != heights[i]) count++;
        }
        return count;
    }
};
