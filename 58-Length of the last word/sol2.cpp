
        
class Solution {
public:
    int lengthOfLastWord(string s) {
         go from last and skip spaces and count characters
      stringstream ss(s);
        string word;
        while(ss >> word){}; // insert words one by one
        return word.length();  /// NOT AN OPTIMAL SOLUTION
       // 27.93% Score
    } 
};
