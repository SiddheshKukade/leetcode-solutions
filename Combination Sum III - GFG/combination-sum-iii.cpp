//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void getCombinations(int idx, int k, int target, vector<vector<int>>& combinations, vector<int>& comb) {
        if(target == 0 && comb.size() == k) {
            combinations.push_back(comb);
            return;
        }
        
        if(comb.size() < k) {
             for(int i = idx; i<=9; i++) {
                 if(target - i < 0) break;
                 comb.push_back(i);
                 getCombinations(i+1, k, target - i, combinations, comb);
                 comb.pop_back();
             }
        }
    }
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
         vector<vector<int>> combinations;
        vector<int> comb;
        
        getCombinations(1, k, n, combinations, comb);
        
        return combinations;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends