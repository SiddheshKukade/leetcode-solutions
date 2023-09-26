//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
 long long ok(string &s, int k, int n)
        {
           int i=0, j=0;
           vector<int>mp(26,0);
           long long ans = 0 ;
           int distinct = 0;
           while( j<n)    // calculating substrings for atmost K
           {
               mp[s[j]-'a']++;
               if(mp[s[j]-'a']==1)distinct++;
               while(distinct>k)
               {
        
                   if(mp[s[i]-'a']==1)
                   {
                       distinct--;
                       mp[s[i]-'a']--;
                   }
                   else
                    mp[s[i]-'a']--;
                   i++;
               }
               ans+=(j-i+1);
               j++;
        
           }

   return ans;


}
    long long int substrCount (string s, int k) {
    	//code here.
    	    int n = s.length();
        long long ans = ok(s,k,n) - ok(s,k-1, n);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends