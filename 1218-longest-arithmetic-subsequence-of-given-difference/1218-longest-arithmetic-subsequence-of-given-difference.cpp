class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> lengths;
        int las=1;
        for(auto el:arr){
            las = max(las, lengths[el] = 1+lengths[el-difference]);
        }
        return las;
    }
};