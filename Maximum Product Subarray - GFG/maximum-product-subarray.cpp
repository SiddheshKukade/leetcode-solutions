//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	
	     
       long prefix = 1 ;
       long suffix = 1;
       long maxprod =arr[0];
       for(int i = 0 ; i < n ; i ++)
       {
           if(prefix==0)prefix = 1;
           if(suffix==0)suffix = 1;
           prefix*=arr[i];
           suffix*=arr[n-i-1];
           maxprod =  max(prefix,max(suffix,maxprod));
       }
       return maxprod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends