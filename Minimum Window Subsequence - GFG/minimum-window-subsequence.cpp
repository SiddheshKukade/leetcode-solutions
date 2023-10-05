//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int s2 = str2.size();
        int s1 = str1.size();
        int win2 = 0;
        int len = INT_MAX, last = -1;
        string ans ="";
        
          for(int i = 0;i<s1;i++){ // checking all combos
            win2 = 0;
            int j = last + 1;
            while(j < s1 && win2 < s2){
                if(win2 < s2 && str1[j] == str2[win2] ){
                    if(win2 == 0) last = j; // if first then set last as Jth to check for further combos
                    win2++;
                }
                if(win2 == (s2) && len > (j - last + 1)){ // if completed substr in subseq then store it as ans
                    len = min(len,j - last + 1);    
                    ans = str1.substr(last,j-last+1);
                }
                j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends