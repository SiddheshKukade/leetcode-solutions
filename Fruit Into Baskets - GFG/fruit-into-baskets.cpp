//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        unordered_map<int, int> count;
        int i , j, ans = INT_MIN;
        
        //sliding windows
        for(int i=0,j=0; j<fruits.size(); ++j){
            count[fruits[j]]++;
            while(count.size() > 2 ){
            //exceeded the limit of fruits
             if(--count[fruits[i]]==0){ // if it was the last one.
                    count.erase(fruits[i]);//delete that single element
                }
               i++; 
            }
            ans = max(ans, j-i+1);  
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends