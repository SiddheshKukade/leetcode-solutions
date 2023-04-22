class Solution {
public:
    int longestPalindromeSubSeq(string& s){
        int n = s.size(); // total size of given string
        vector<int> dp(n), dpPrev(n); // current and previos 
        for(int start = n-1; start>=0; --start){ // from last to 0
            dp[start] = 1; // insert 1 at current pos
            for(int end = start+1; end<n;++end){ // from next to the last point of the stirng
                if(s[start] == s[end]){ // if same ele
                    dp[end] = dpPrev[end-1] + 2; // curr set to prev + 2 pos
                }else{ // if not equal
                // if set end to max element matching
                    dp[end] = max(dpPrev[end], dp[end-1]);
                }
            }
            dpPrev= dp;
        }
        return dp[n-1];
    } 
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubSeq(s);
    }
};
