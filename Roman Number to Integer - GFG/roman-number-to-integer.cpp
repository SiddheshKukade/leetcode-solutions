//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
               map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
     mp['L'] = 50;
     mp['C'] = 100;
     mp['D'] = 500;
     mp['M'] = 1000;
    int n = s.size();
    int ans = mp[s[n-1]];

    for(int i = n-2; i>=0; i--){
        if(mp[s[i]] < mp[s[i+1]]){
            ans -= mp[s[i]] ;
        }else{
            ans += mp[s[i]];
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends