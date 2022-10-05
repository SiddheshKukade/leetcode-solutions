class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size() , -1);
        return nways(0,s);
    }
    int nways(int i  , string s ){
        //we have complete scanning the string then return 1;
        if(i>=s.size() ) return 1;
        //if it is 0 return 0 because no character represents zero
        else if (s[i]=='0') return 0;
        //if one char is left then return 1 as we can form only maximum one character with it
        else if (i==s.size() -1 ) return 1;
        else if (dp[i] != -1) return dp[i];
        // for 1x , 2x test cases the condition is used
//         the 48 and 54 are ASCII values  for 0 and 6 (using ASCII because the numbers are coming in strings)
        else if(s[i] == '1' || (s[i] == '2' && (s[i+1]>=48 && s[i+1]<=54)))
//       if Yes for 1x or  2x we can form a pair by combining thier values ex 13-> m (1 + 3)
            return dp[i] = nways(i+1,s) + nways(i+2,s);
        //just keep returning the next point of stirng to continue the program
      else  return dp[i]= nways(i+1,s);
    }
   
};
