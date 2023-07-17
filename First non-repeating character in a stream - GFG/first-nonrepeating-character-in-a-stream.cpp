//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    vector<int> f(26,0);
		    queue<int> q;
		    for(auto i: A){
		        ++f[i-'a'];
		        if(f[i-'a'] == 1){
		            q.push(i);
		        }
		        while(q.size() and f[q.front() - 'a'] > 1)
		            q.pop();
		        if(q.size())
		            ans += q.front();
		        else
		            ans += '#';
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends