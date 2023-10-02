//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int nnn, vector<int>& nums, int k) {
        // Code here
           int i=0, j = 0;
        int n = nums.size();
        while (i<n) {
            if (!nums[i]) k--;
            if (k < 0) {
                if (!nums[j]) k++;
                j++;
            }
            i++;
        }
        return i-j;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends