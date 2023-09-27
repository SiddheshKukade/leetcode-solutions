//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int beauty(vector<int> &alpha){ // find the max min occurennes and return the result.
        int mf = -1;
        int lf = 1e9;
        for(int i=0; i<26; i++){
            mf = max(mf, alpha[i]);
            if(alpha[i] >= 1){
                lf = min(lf, alpha[i]);
            } 
        }
        return mf - lf;
    }
    int beautySum(string s) {
        // Your code goes here
                int res= 0 ;
        for(int i=0; i< s.size(); i++){
            vector<int> alpha(26,0);
            for(int j=i; j<s.size(); j++){
                alpha[s[j]-'a']++;
                res = res + beauty(alpha); 
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends