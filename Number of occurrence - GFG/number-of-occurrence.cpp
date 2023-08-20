//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
   int binarySearch(int a[],int n,int e)
        {
            int beg=0,end=n-1,mid=(beg+(end-beg)/2);
            while(beg<=end)
            {
             mid=(beg+(end-beg)/2);
             if(a[mid]==e)
             return mid;
             else if(a[mid]<e)
             beg=mid+1;
             else
             end=mid-1;
            }
            return -1;
        }
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
   int s = 0;
	    int e = n-1;
	    
	    while(s <= e){
	        int mid = s+(e-s)/2;
	        
	        if(arr[s] == x && arr[e] == x){
	            return e-s+1;
	        }
	        if(arr[mid] == x){
	            if(arr[s] != x){
	                s++;
	            }
	            if(arr[e] != x){
	                e--;
	            }
	        }
	        else if(arr[mid] > x){
	            e = mid-1;
	        }
	        else if(arr[mid] < x){
	            s = mid+1;
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