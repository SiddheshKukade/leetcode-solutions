class Solution {
public:
    // int solve(vector<int>& sat , int index, int time){
    //     if(index == sat.size()){
    //         return 0;
    //     }
    //     int include = (sat[index] * (time+1)) + solve(sat, index+1, time+1);
    //     int exclude = 0 + solve(sat, index+1, time);

    //     return max(include,exclude);
    // }
    // int solve
        int solveMem(vector<int>& sat , int index, int time, vector<vector<int>> &dp){
        if(index == sat.size()){
            return 0;
        }
        if(dp[index][time] != -1){ return dp[index][time];}

        int include = (sat[index] * (time+1)) + solveMem(sat, index+1, time+1,dp);
        int exclude = 0 + solveMem(sat, index+1, time,dp);

        return dp[index][time] = max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        return solveMem(satisfaction, 0,0,dp);
        // return solve(satisfaction, 0,0);
    }
};
