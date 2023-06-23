class Solution {
public:
    bool isVowel(char ch){
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
    }
    string reverseVowels(string ch) {
        //using two pointers start and end;
        int start=0, end=ch.size()-1;
        while(start<=end){
              bool isLowVowel = isVowel(ch[start]);
            bool isHighVowel = isVowel(ch[end]);
          
            if(isLowVowel && isHighVowel){
                // now both the pointers must be on vowels
                char temp = ch[start];
                ch[start] = ch[end]; /// SWAP 
                ch[end] = temp;
                start++; end--;
            }
              if(!isLowVowel){
                start++;
            }
            if(!isHighVowel){
                end--;
            }
        }
        return ch;
    }
};
