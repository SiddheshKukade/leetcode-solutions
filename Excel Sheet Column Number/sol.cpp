class Solution {
    public int titleToNumber(String s) {
           // 26*26+25 => 701
        /////  "ZY" => 701
        // //keep increasing the power of 26 as you go from left to right.
        // to convet from A to Z to 0 to 26 
        // do this
        // A - 65 +1 gives the A to Z index level value
        int ans =0;
        int p=0;
        for(int i=s.length()-1; i>=0;i--){
            int c = s.charAt(i);
            int val  =(int) c - 65+1 ;
            ans += val* Math.pow(26,p);
            p++;
        }
        return ans;
    }
}
