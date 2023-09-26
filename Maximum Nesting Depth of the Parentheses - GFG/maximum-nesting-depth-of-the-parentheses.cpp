//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
    
        int maxCount = 0;
    int openCount = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            maxCount = max(maxCount, ++openCount);
        } else if (s[i] == ')') {
            openCount--;
        }
    }
    
    return maxCount;
        
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends