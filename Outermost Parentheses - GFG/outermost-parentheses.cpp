//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
      int n = s.size();
        int tp =0;
        string ans ="";
        for(int i=0; i<n; i++){
                if(s[i] == '('){
                    if(tp != 0) ans += s[i];
                    tp++;
                }else if(s[i] == ')'){
                    tp--;
                    if(tp !=0) ans = ans + s[i];
                }
        }
        return ans;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends