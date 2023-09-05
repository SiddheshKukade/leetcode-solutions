//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
  /*
    *
   ***  
  *****
 *******
*********
*/
    void printTriangle(int n) {
        // code here
        for(int row =1; row<=n;row++){
            //spaces
            for(int col=n-row;col>=1;col--){
                cout<<" ";
            }
            //stars curr i + prev i is no of stars
            for(int i=0; i< row+(row-1); i++) cout<<"*";
            cout<<endl; }
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends