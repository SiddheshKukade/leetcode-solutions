class Solution {
    public boolean isPalindrome(int x) {
        String temp = Integer.toString(x);
        boolean toggle =false;
        int[] numArray = new int[temp.length()];
        for (int i = 0; i < temp.length(); i++)
{
    numArray[i] = temp.charAt(i) - '0';
}
if(numArray.length ==1) return true;
        for (int i = numArray.length-1,  j =0; i >= 0 && j<numArray.length-1; i--, j++) {  
           if(numArray[i] == numArray[j]){
               toggle = true;
           }
         else{
             toggle = false;
             break;
         }
        }  
        return toggle;
        
        }
}
