//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    //looks like greedy problem
  vector<int> f(26 , 0);
        int n = s.length();
        int l = 0 , h = 0,unique = 0,ans = -1;
        while(h < n){
            f[s[h]-'a']++;
            if(f[s[h]-'a'] == 1) unique++;
            while(l < h && unique > k){
                f[s[l]-'a']--;
                if(f[s[l]-'a'] == 0) unique--;
                l++;
            }
            if(unique == k){
                ans = max(ans , h-l+1);
            }
            h++;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends