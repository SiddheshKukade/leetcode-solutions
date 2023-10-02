//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	            const int M = 1e9+7;
        int n = s.length();
        vector<long long int> dp(s.length()+1);
        dp[0] = 1;
        map<char,int> hashmap;
        for(int i = 1;i <= n;++i){
            dp[i] = 2 * (dp[i-1]%M);
            if (hashmap.find(s[i-1]) != hashmap.end()){
                dp[i] = (dp[i]%M - (dp[hashmap[s[i-1]]-1])%M+M)%M;
            }
            hashmap[s[i-1]] = i;
        }
        return dp[n]%M;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends