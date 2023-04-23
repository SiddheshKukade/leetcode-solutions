#define mod 1000000007
class Solution {
public:
    // int dp[100001];
    // int help(string &s, int i , int k){
    //     if(i==s.size()) return 1; // if end then return 1
    //     if(dp[i] != -1) return dp[i]; // if NOT -1 then return 1 
    //     else{
    //             if(s[i]=='0') return 0;
    //             long long num=0;
    //             int ans =0;
    //             for(int j=i;j<s.size();j++){
    //                 num= num*10 + s[j]-'0'; // combine all remaining
    //                 if(num>k) break; // if k exceeded then can't move forward
    //                 ans += help(s,j+1,k); //
    //                 ans %= mod;  // making sure that no is within raange
    //             }
    //             return dp[i]= ans;
    //     }
    // }
    int dfs(const string& s, long k, int i, vector<int>& dp) {
      if(i==s.size() ) return 1;
     if(s[i]=='0') return 0;
     if(dp[i]!= -1) return dp[i]; // MEMOIZATION
     int ans=0;
     long num=0;
        for(int j=i;j<s.size();j++){ 
            num= num*10 + s[j]-'0'; // pushing the next int to the current number
                if(num>k) break;
                ans += dfs(s,k,j+1,dp); //
                ans %= mod;
        }
      return dp[i] = ans;
      }
    int numberOfArrays(string s, int k) {
    //    for(int i=0;i<=s.size();i++){
    //        dp[i] = -1; // set all to -1
    //    } 
    //    return help(s,0,k);

        vector<int> dp(s.size(), -1);
        return dfs(s, k, 0, dp);

    }
};
// class Solution {
// public:
//     int dfs(const string& s, long k, int i, vector<int>& dp) {
//         if (i == s.size()) return 1;
//         if (s[i] == '0') return 0;
//         if (dp[i] != -1) return dp[i];

//         int ans = 0;
//         long num = 0;
//         for (int j = i; j < s.size(); j++) {
//             num = num * 10 + s[j] - '0';
//             if (num > k) break;
//             ans = (ans + dfs(s, k, j + 1, dp))%1000000007;
//         }
//         return dp[i] = ans;
//     }

//     int numberOfArrays(string s, int k) {
//         vector<int> dp(s.size(), -1);
//         return dfs(s, k, 0, dp);
//     }
// };
