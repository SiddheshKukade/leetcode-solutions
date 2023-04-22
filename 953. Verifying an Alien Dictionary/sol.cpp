class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] mapping = new int[26];
        int seq= 0;
        for(char ch: order.toCharArray()){ // breaks to char arry and iterate over one at a time
            mapping[ch-'a'] = seq++; // mapped char with location
        }
        for(int i=0; i<words.length-1; i++){
            String curr = words[i];
            String next = words[i+1];
            int len = Math.min(curr.length(), next.length()); // taking min of both words

//checking edge case where second string is subset of curr stirng 
            if(len!= curr.length() && len == next.length() && curr.startsWith(next)){
                return  false;
            }

            for(int l=0; l<len;l++){ // untill the min length
                if(mapping[curr.charAt(l)-'a'] > mapping[next.charAt(l)-'a']){ // if char has seq larger than current
                    return false; // so not lexographifcally order
                }
                if(mapping[curr.charAt(l)-'a'] < mapping[next.charAt(l)-'a']){
                    break; // if lower then current word is ok and we can check for next set of curr and next words.
                }
            }
        }
        return true;
    }
}
