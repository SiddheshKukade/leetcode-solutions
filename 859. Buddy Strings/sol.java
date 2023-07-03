class Solution {
    public boolean buddyStrings(String A, String B) {
        if(A.length() != B.length()) return  false;
        if(A.equals(B)){ /// edge case for A == B aa aa returns false
            HashSet<Character> unique = new HashSet();
            for(char c: A.toCharArray()){
                unique.add(c);
            }
            if(unique.size() < A.length()){ // all chars are same 
                return true;
            }else return false;
        }
        List<Integer> diff = new ArrayList(); // contains list of different indexes
        for(int i=0; i<A.length(); i++){
            if(A.charAt(i) != B.charAt(i)){
                diff.add(i);
            }
        }
        if(diff.size()  == 2  && A.charAt(diff.get(0)) ==B.charAt(diff.get(1))
            && B.charAt(diff.get(0)) == A.charAt(diff.get(1)))
         {
            return true;
        }
        return false;
    }
}
