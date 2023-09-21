//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getNum(int arr[] , int N) {
       

if(N==1){
           return arr[0];
       }
       
       int maxi = *max_element(arr,arr+N);
       int mini = *min_element(arr,arr+N);
       
       
       return mini*maxi/__gcd(mini,maxi);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.getNum(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends