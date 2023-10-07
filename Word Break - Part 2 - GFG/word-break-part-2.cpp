//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void solve(int n , unordered_set<string> temp, string s, int index, vector<string>&ans, string res){
    if(index >= s.size()){
        res.pop_back();
        ans.push_back(res);
        return;
    }
    string v = "";
    for(int i = index ; i<s.length(); i++){
          v+=s[i];
            if(temp.find(v)!=temp.end())
            {
                solve(n,temp,s,i+1,ans,res+v+" ");
            }
        }
        return ;
}
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
  vector<string>ans;
      unordered_set<string>temp;
      for(int i=0; i<dict.size(); i++)
      {
          temp.insert(dict[i]);
      }
      solve(n,temp,s,0,ans,"");
      return ans;
      
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends