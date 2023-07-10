//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // int f(int ind , int prev,int n, int arr[],vector<vector<int>> &dp){
    //     if(ind ==n) return 0;
    //     if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    //     int len = 0 + f(ind+1, prev, n, arr,dp);
    //     if(prev == -1 || arr[ind]> arr[prev]){ // no take
    //         len = max(len,1+f(ind+1, ind, n,arr,dp)); // take
    //     }
    //     return dp[ind][prev+1] = len;
    // }
        int optimalSolution(int n,int arr[]){
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int idx=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[idx]=arr[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
    //   vector<vector<int>> dp(n,vector<int>(n+1, -1));
    //   return f(0,-1,n,arr,dp);
            return optimalSolution(n,arr);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends