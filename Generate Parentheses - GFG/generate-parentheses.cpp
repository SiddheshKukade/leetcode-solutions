//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
void solve(int i,int  n,   vector<string>  &ans , int open , int close, string &s){
  if(i == n )
  {
    ans.push_back(s);
    return ;
  }
  if(open>0 && i != n-1){
    s+="(";
    solve(i+1,n, ans, open-1 ,close, s);
    s.pop_back();
  }
  if(close>0 && open < close){ // if more pending to close
    s+=")";
    solve(i+1, n, ans ,open , close-1, s);
    s.pop_back();
  }
  
  
}
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
         vector<string> ans;
    int open = n-1;
    int close = n;
    n = 2 * n ;
  string s = "(";
    solve(1,  n, ans , open, close,s);
  return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends