//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
         int left = 0;
        int right = s.size()-1;
        string ans ="";
        string temp ="";
        while(left <= right){
            if(s[left] != '.'){
                temp =  temp + s[left];
            }else if(s[left] == '.'){
                if(ans != ""){
                    if(temp != "") ans = temp + "." + ans;
                }else{
                    ans = temp;
                }
                temp="";
            }
            left++;
        }
        if(temp != "") {
            if(ans!="") ans = temp +"."+ ans;
            else ans = temp;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends