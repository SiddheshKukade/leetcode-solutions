//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void sol(string s, vector<string> &ans , int ind){
        if(ind == s.length()){
            ans.push_back(s);
            return;
        }
        for(int i= ind; i< s.length(); i++){
            swap(s[i], s[ind]); // swap each element once with index and call func
            sol(s,ans,ind+1);
            swap(s[i], s[ind]); // make it original again
        }
    }
    vector<string> permutation(string S)
    {
 //Your code here
        vector<string> ans;
        sol(S,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends