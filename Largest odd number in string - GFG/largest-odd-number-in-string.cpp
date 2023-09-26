//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string num) {
          bool isOdd =false;
    string ans = "";
    int last = -1;
    for(int i =num.size()-1; i>=0; i--){
        if(num[num.size()]-'0' % 2 ==1 ){
             return num;   
        }
        if((num[i]-'0') % 2 ==1 ){
            last = i;
            break; 
        } 

    }
    if(last < 0 ) return "";
    return num.substr(0, last+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends