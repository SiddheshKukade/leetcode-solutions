//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String s = read.readLine().trim();

            Solution ob = new Solution();
            System.out.println(ob.longestUniqueSubsttr(s));
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution{
    int longestUniqueSubsttr(String s){
             int  a = 0  , b = 0  ,max= 0 ;
 HashSet<Character> hashSet  =new HashSet();

            while(b < s.length()){
            if(!hashSet.contains(s.charAt(b))) {
                    //if it don't contain same char then add it to the  list
                hashSet.add(s.charAt(b));
                b++;
                max = Math.max(hashSet.size(), max);
            }
            else{
                //if duplicate found remove previous instance and add new instannce and follow same process at last you'lll get longest substring without repeating characters.
                 hashSet.remove(s.charAt(a));
                 a++;
            }
    }
        return max;
    }
}