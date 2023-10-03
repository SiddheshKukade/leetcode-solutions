//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
         if(s.size() == 0 )  return 0;
     vector<int> arr(128);
     int beg = 0, largestCnt =0;
     for(int end =0; end<s.size(); end++){
         largestCnt = max(largestCnt , ++arr[s[end]]);
         if(end- beg + 1  - largestCnt >k ){ 
            arr[s[beg]]--; beg++;}
     }
     return s.length() - beg;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends