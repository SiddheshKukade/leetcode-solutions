class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), result =0 ;
        while(n>0){
            if(s[--n] != ' ') result ++; /// traversig to the string from the back
            else if (result > 0) return result;
        } 
        return result;
        //0ms RUNTIME 100% 51.81
    } 
};
