//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool possible(vector<int> &arr, int day, int m, int k) {
    //check if possible to have m bouqets after day days, grouped by k flowers
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
    int solve(int m, int k, vector<int> &bloomDay){
       long long aa = m *1LL* k*1LL ;
        long long n = bloomDay.size();
        if(aa > n) return -1;
        int st = *min_element(bloomDay.begin(), bloomDay.end()), en = *max_element(bloomDay.begin(),bloomDay.end());
        int mid, ans = en;
        while(st<=en){
            mid = st + (en-st) /2;
            if(possible(bloomDay, mid, m ,k))
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends