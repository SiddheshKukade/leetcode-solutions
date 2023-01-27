class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
     // Couting the freY of all words in a map.
     // Break word one by one and check if that exists in the map.
     // if not found but prev string is found try checking if an combination exists for that ex. cat and cats checkking for the char 's'.   
     // we will check for all posible combinations
     unordered_map<string, int> words_map;

     for(string word: words){
         words_map[word]++;
     }
     vector<string> res;
     for(string word: words){
         int n = word.size();
         vector<int> dp(n+1, 0); // to keep track of found words
         dp[0]=1;
         for(int i=0; i<n;i++){
            if(!dp[i]) // if prev words are not present then also on't check for current char
                continue;
             for(int j=i+1; j<=n;j++){ //checking all the combo of current char with each combo of previous stirng.
                if(j-i<n && words_map[(word.substr(i,j-i))] > 0) // is the substring available
                    dp[j]=1;
             }
             if(dp[n]){ // if last char is also found in the word then we can add it to answer
                 res.push_back(word);
                 break;
             }
         }
     }
     return res;
    }
};
