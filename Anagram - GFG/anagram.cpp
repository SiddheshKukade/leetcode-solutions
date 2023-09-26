//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t){
        
        // Your code here
           if(s.size() != t.size()) return false;
        map<char, int>mp;

        for(char c: s){
                mp[c]++;
         }
           for(char c: t){
                mp[c]--;
         }
       for(int i=0; i<t.size(); i++){
           if(mp[t[i]] !=0 ) return false;
       }
      
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends