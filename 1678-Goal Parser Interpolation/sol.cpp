class Solution {
    public String interpret(String str) {
        StringBuilder sb = new StringBuilder("");
        for(int i=0;i<str.length();i++){
            if(str.charAt(i) == 'G')
            sb.append("G");
            else if (str.charAt(i) == '('){
                if(str.charAt(i+1) == ')'){
                    sb.append("o");
                }else{
                    sb.append("al");
                }
            }
        }
        return sb.toString();
    }
}
