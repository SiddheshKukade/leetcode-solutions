class Solution {
public:
    // int rec(int n ){
    //     if(n<=1) return 1; // base case
    //     int op1 = rec(n-1);
    //     int op2= rec(n-2);
    //     return op1+op2;
    // }
    // int climbStairs(int n) {
    //     int memo[] 
    //     int ans = rec(n);
    //     return ans;
    // }
    int climb(int n,vector<int>&dp){
        if(n==0||n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=climb(n-1,dp)+climb(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=climb(n,dp);
        return ans;
    }
};
