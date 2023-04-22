class Solution {
    public String freqAlphabets(String s) {
        StringBuilder sb= new StringBuilder();
        int n=s.length();// total lengthh
        int i=0; // index
        while(i<n){ // eo str
            if( (i+2) < n &&  s.charAt(i+2) == '#' ) // if next second is #
                {
                    // get that substr parse as int and then get ascii char append
                    // to ans and move 3 pos
                    String str = s.substring(i, i+2); // next 2 chars
                    int tmp = Integer.parseInt(str);
                    char ch = (char)(tmp+96);
                    sb.append(ch);
                    i+=3;
                }
            else{
                //else convert the single one to chars
                
                    char ch = s.charAt(i);
                    sb.append((char)(ch+48));
                    i++;
                }
        }
        return sb.toString();
    }
}
