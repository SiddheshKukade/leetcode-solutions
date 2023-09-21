//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:    
  int fn(vector<int> &bananas, int hourRate){
      int ans =0;
      for(int i=0; i<bananas.size(); i++ ){
        //   float f = bananas[i] / hour
          ans += ceil((double)bananas[i] / (double) hourRate);
      }
      return ans;
    }
    
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int st = 1, en = *max_element(piles.begin(),piles.end());
        int mid;
        while(st<=en){
            mid = st + (en-st) /2;
            int  t = fn(piles, mid);
            if(t<= H)
            {
         
                en = mid -1;
            } 
           else{  st = mid+1; }
        }
        return st;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends