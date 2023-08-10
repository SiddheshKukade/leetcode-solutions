//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int f(int i, int j, string &s, string &t,
    vector<vector<int>> &dp
    ){
        if(i<0 || j<0) return 0;
      
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j]= 1+f(i-1, j-1, s,t,dp);
        return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
        
        
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s, string t)
    {
        // DP ON Strings
    /// subsequence- every string is subsequence for ex abc can have a,b,c,ab,ac,bc
    //as long as it maintains the order of chars
    /// sol poweset or recursion
    
    ///brute force- generate all raised to n subswquences and check them
    ////tc would be exponential in nature.
    
    ///using some recurrence
    ///rules for recursion
    //express ind
    //explore ind
    //take out the best case between them
    
    ///in recursion we are taking one smaller and one larger string
    // ex. f(3,5) -> LCS between s1[0..3] & s2[0..5]
    
    ///recruion has match and not match step.
    
    // int n = s.size();
    // int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1,m-1, s,t, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends