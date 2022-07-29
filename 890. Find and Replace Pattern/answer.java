class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<>();
        
        for(String word: words){
            if(matches(word,pattern)){
                result.add(word);
            }
        }
        return result;
    }
    private boolean matches(String word , String pattern){
        char [] patternToWord = new  char[26];   // keeping record of all 26 alphabets with which is mapped to which varaible
        char [] wordToPattern = new  char[26];
        
        for(int index = 0 ; index<word.length(); index++){
            char wordChar = word.charAt(index);
            char patternChar = pattern.charAt(index);
            
            if(patternToWord[patternChar -'a'] == 0 ){  
//                 // ex. b-a == 1-0 = 1   ex. d-a = 3
                patternToWord[patternChar - 'a'] = wordChar;
            }
            
              if(wordToPattern[wordChar -'a'] == 0 ){
                wordToPattern[wordChar - 'a'] = patternChar;
            }
            if(patternToWord[patternChar - 'a'] != wordChar || 
              wordToPattern[wordChar - 'a'] != patternChar){
                return false;
            }
        }
        return true;
    }
}
// so basically we have to map the character according to the patterns and check if correct matching is being done if anyone tries to break the pattern we can easily find out by comparing with it's previous matching 
// A character in a map should be only matched to ONE word 
// note : if previous doesn't exists then the pattern is still building or no pattern exists 
