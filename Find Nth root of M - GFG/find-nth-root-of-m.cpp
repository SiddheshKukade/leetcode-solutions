//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private: 
    int fn(int mid, int n , int m){
        long long  ans=1;
        for(int i=0;i<n; i++){
            ans = ans * mid;
            if(ans > m) return 2;
            //  n =n-1;  
        }
        if(ans == m){
            return 1;
        }else if(ans < m){
            return 0;
        }
        return 2;
    }
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int st = 0,
	     en = m;
	    int mid;
	    while(st<=en){
	        mid = st + (en-st)/2;
	        int t = fn(mid, n,m); 
	        if(t == 1 ){
	            return mid;
	        }else if(t == 2){
	            en = mid -1;
	        }else st = mid+1;
	        
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends