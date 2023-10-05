//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        
      // Your code here
        int start_idx=0,j=0,len=INT_MAX;
        vector<int>v(26,0);
       
        for(int i=0;i<p.size();i++){
            v[p[i]-'a']++;
        }
        int need=0;
        for(int i=0;i<26;i++){
            if(v[i]!=0)
            need++;
        }
        int have=0;
        vector<int>cur(26,0);
       
        for(int i=0;i<s.size();i++){
            cur[s[i]-'a']++;
            if(v[s[i]-'a']==cur[s[i]-'a'])
            have++;
            while(have==need){
                if(len>(i-j+1)){
                    len=i-j+1;
                    start_idx=j;
                }
                cur[s[j]-'a']--;
                if(v[s[j]-'a']>cur[s[j]-'a'])
                have--;
                j++;
            }
        }
        if(len==INT_MAX)return "-1";
        string ans=s.substr(start_idx,len);
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends