//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    int N = 1000000007;
	    long long int a = 1, b=2;
	    long long ans =0;
	    if(n == 0 ) return a;
	    
	    if(n == 1) return b;
	    
	      for(int i=2; i<=n; i++){
            ans = a%N + b%N;
            a = b;
            b = ans;
        }
        return ans%N;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends