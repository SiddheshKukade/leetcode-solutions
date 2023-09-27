//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here4
              // Your code goes here
        int ans = 0;
        
        for(int i = 0; i<s.length();i++)
        {
            int arr[26] = {0};
            for(int j = i; j<s.length(); j++){
            
                arr[s[j]-'a']++;
                int maxi = 0 , mini = INT_MAX; 
                for(int k = 0; k<26; k++){
                
                    if(arr[k] > 0){
                        
                        maxi = max(maxi , arr[k]);
                        mini = min(mini , arr[k]);
                            
                    }
                }   
        
                ans += (maxi - mini);
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
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends