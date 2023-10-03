//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int odd =0;
        int i = 0;
        int ans =0;
        int count =0;
        for(int j =0; j<n ; j++){
            if(nums[j] % 2 ==1){
                odd++;
                if(odd >=k){
                    count =1;
                    while(nums[i++] % 2 == 0 ){ count++;}
                    ans+=count;
                }
            }else if(odd >= k){
                ans += count;
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
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends