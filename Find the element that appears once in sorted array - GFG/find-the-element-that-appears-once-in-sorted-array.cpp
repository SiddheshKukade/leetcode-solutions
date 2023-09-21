//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
     	///TC ON SC O 1
 
	if(n ==1 ) return arr[0];

	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return  arr[n-1];

	int low = 1,
	high = n-2;

	while(low<=high){
		int mid = low + (high - low) /2;
		if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
			return arr[mid]; // found it
		}else{
			//check left
			if((mid % 2 ==1 && arr[mid ] == arr[mid-1]) || 
				(mid % 2 == 0 && arr[mid] == arr[mid +1])
			){
				low = mid+1; // ans not present here so skip it.
			}else{ /// ans might be of the left side to skip the right part
				high = mid -1;
			}
		}
	}
	return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends