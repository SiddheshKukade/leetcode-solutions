//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int atMostK(vector<int>& arr,int N,int k){
        vector<int> v(N+1,0);
        int i=0,j=0,ans=0,size=0;
        while(j < N){
            v[arr[j]]++;
            if(v[arr[j]] == 1) size++;
            if(size <= k) ans += j-i+1;
            else{
                while(size > k){
                    v[arr[i]]--;
                    if(v[arr[i]] == 0) size--;
                    i++;
                }
                ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
          // code here
        return atMostK(arr,N,k) - atMostK(arr,N,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends