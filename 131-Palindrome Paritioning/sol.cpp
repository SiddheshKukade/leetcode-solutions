class Solution {
public:
    vector<vector<string>> partition(string s) {
        //keep breaking the string and keep finding the combos to make each element in that //combo a palindrome string
        //every substring has to be a palindrome
        /*
        steps 
        1. crete partitions 
        2. check for palindrome
            // true - add to answer
            // false - ignore
        */
        vector<vector<string>> res ;
        vector<string> path ; 
        func(0, s, path ,res);
        return res;
    }
    void func(int index ,string s, vector<string> &path,vector<vector<string>>&res){
        if(index==s.size()){ // if reached till the end sucessfully
            res.push_back(path); // add the path to the answer
            return ;
        }
        for(int i=index ; i<s.size() ; ++i){
            if(isPalindrome(s,index, i)){ //check for each partition
                path.push_back(s.substr(index, i-index+1));
                func(i+1, s, path, res); // check for the next partition
                path.pop_back(); // backtracking
            }
        }
    }
    //main logic
    //palindrome checkk 
    bool isPalindrome(string s , int start , int end){
        while(start <=end){
          if(s[start++] != s[end--]) return false;  
        }
        return true;
    }
};
