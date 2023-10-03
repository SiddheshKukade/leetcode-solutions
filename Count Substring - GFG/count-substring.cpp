//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
               int n = s.size();
        int i=0, j=0, count=0;
        unordered_map<char, int> mp;
        while(j<n){
            mp[s[j]]++;

            while(mp['a'] >=1 && mp['b'] && mp['c']){
                 count += (n - j);

                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
  
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends