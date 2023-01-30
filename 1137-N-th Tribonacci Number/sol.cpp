class Solution {
public:
 int tribonacci(int n) {
    //  maintain 3 nos 
    // just like fibonacci
    int t1=0;
    int t2=1;
    int t3=1;
    int ans=0;

    if(n==0){
        return t1;
    }
    else if(n==1 || n==2){
        return t2;
    }
    int  i=3;
    while(i<=n){
         ans = t1+t2+t3;
        t1 = t2;
        t2=t3;
        t3=ans;
        i++;
    }
    // 0 1 1 2 4
    return ans;
        // if(n == 0) return 0;
        // if(n == 1 || n == 2) return 1;

        // if(dp[n] != -1) return dp[n];

        // return dp[n] = tribonacciHelper(n-1, dp) + tribonacciHelper(n-2, dp) + tribonacciHelper(n-3, dp);
    }

    // int tribonacci(int n) {
    //     vector<int> dp(n+1, -1);
    //     return tribonacciHelper(n, dp);
    // }
};
