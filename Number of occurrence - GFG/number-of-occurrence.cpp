//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
   int s = 0;
	    int e = n-1;
	    //norm bs condition
	    while(s <= e){
	        ///normal  mid from start to end
	        int mid = s+(e-s)/2;
	        ///if start or end is the same number
	        if(arr[s] == x && arr[e] == x){
	            //return count of all nos between them
	            return e-s+1;
	        }
	        if(arr[mid] == x){ /// if mid is the no
	            if(arr[s] != x){ /// if start is not the no
	                s++; // increase  start
	            }
	            if(arr[e] != x){ // end not the no 
	                e--;// reduce range (decrease end)
	            }
	        }
	        else if(arr[mid] > x){ // if mid more than x 
	            e = mid-1; // go to left
	        }
	        else if(arr[mid] < x){
	            s = mid+1; // go to right
	        }
	    }
	    return 0;
	}
// 	  return -1;
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends