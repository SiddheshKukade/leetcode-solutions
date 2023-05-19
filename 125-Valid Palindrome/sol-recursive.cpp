class Solution {
public:
    bool revStr(string &sol, int i ){
        int len = sol.length();
        if(i>=len/2) return true; // BASE CASE reached halfways means comparision is completed.
        else if(sol[i] != sol[len-i-1]) return false; // if not equal return false
        return revStr(sol,i+1); // else keep moving
    }
    bool isPalindrome(string s) {
        string sol;
        for(int i=0; i<s.length();i++){
            //insert only numbers and letter that are valid in the solution
            if(s[i]>='A' && s[i]<='Z') sol.push_back(tolower(s[i]));
            else if(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9') sol.push_back(s[i]);
        }
        return revStr(sol,0);
    }
};
