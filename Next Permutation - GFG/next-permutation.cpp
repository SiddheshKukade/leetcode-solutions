//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> A){
        // code here
        int ind = -1;
        
        int n = A.size();
        for(int i=n-2; i>=0; i--){ // from reverse
            if(A[i] < A[i+1]){ // check if the graph is NOT on increasing side
            /// then breakpoint found
                ind = i; // mark it
                break;
            }
        }
        ///STEP 1 get the index
        if(ind  == -1){ /// if breakpoint doesn't exits
            reverse(A.begin(), A.end());
            return A;
        }
        ///breakpoint exists.
        
        //STEP 2 : Get the most optimal element at index to swap with idx pos
        for(int i=n-1; i>ind; i--){
            if(A[i] > A[ind]){ /// only want the first bigger element
                swap(A[ind] , A[i]);
                // so breaking heere
                break;
            }
        }
        //STEP 3 
        reverse(A.begin()+ind+1, A.end());
        
        return  A;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends