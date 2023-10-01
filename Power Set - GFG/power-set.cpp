//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	

  void solve(string s,vector<string>&st,int ind,string &str)
	  {
	      if(ind>=s.size())
	       {
	           return ;
	       }
	       for(int i=ind;i<s.size();i++)
	       {
	           str+=s[i];
	           solve(s,st,i+1,str);
	           st.push_back(str);
	           str.pop_back();
	       }
	  }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		     int i=0;
		    vector<string>st;
		    string str="";
		    solve(s,st,i,str);
		    sort(st.begin(),st.end());
		    return st;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends