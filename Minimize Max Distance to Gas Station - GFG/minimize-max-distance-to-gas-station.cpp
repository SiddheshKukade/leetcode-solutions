//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}


    double findSmallestMaxDist(vector<int> &stations, int K){
      // Code here
int n = stations.size();
    
    double left = 0.0, right = stations[n-1] - stations[0];

    while (right - left > 1e-9) {
        double mid = (left + right) / 2;
        int requiredStations = 0;

        for (int i = 0; i < n - 1; i++) {
            requiredStations += int((stations[i + 1] - stations[i]) / mid); // stations with gap mid
        }

        if (requiredStations <= K) { // right is returned if they are equal to k gas stations
            right = mid;
        } else {
            left = mid;
        }
    }

    return right; 
}
// time complexity : O(logK) for binary search and O(N) for for loop inside while
                    //O(NlogK);
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends