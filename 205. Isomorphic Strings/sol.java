class Solution {
    public boolean isIsomorphic(String s, String t) {
        // a single char in one string is mapped to another cha in second string
        // one to one mapping is present everywhere then the string is ISOMORPHIC.
       
       if(s.length() != t.length())
            return false;    

        HashMap<Character, Character> map1= new HashMap<>();
        HashMap<Character, Boolean> map2= new HashMap<>();

        for(int i=0;i<s.length();i++){
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
    if(map1.containsKey(ch1) == true){
        if(map1.get(ch1) != ch2){ // if chars were not matching
            return false;
        }
    }
    else{
         if(map2.containsKey(ch2) == true){ //if char is already occupied
            return false;
        }
            //adding them in the map
            map1.put(ch1, ch2);
            map2.put(ch2,true);
        }
    }
        return true;
        }
}
