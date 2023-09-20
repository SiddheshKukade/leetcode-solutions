//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int xxx, vector<int>& arr, int x) {
       int n = arr.size();
    int low = 0;
	int high = n -1;
	int mid;
	int ans = n;
	while(low<=high){	
		mid  = low+ (high-low) /2 ;
        if(arr[mid] == x) return true;
        if(arr[mid] == arr[low] && arr[mid] == arr[high]) {
            low+=1;
            high-=1;
            continue;
        }
		if(arr[low] <= arr[mid]){ // this part is sorted
            if(arr[low] <= x && x <= arr[mid]){
                high = mid -1;
            }else{
                low = mid+1;
            }
        	// low = mid+1;
		}else{ // not sorted
			if(arr[mid] <= x && x <= arr[high]){
                low = mid +1;
            }else{
                high = mid-1;

            }
		}
	}
	return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends