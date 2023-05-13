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
    int solveTab(vector<int>& sat){
        int n =sat.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
        
        for(int i = n-1; i>=0;i-- ){
            for(int time = i; time>=0 ;time--){
                 int include = (sat[i] * (time+1)) + dp[i+1][time+1];
                 int exclude = 0 +  dp[i+1][time];

                 dp[i][time] = max(include,exclude);
            }
        }
        return dp[0][0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // int n = satisfaction.size();
        // vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        // return solveMem(satisfaction, 0,0,dp);
        // return solve(satisfaction, 0,0);
        return solveTab(satisfaction);
    }
};
