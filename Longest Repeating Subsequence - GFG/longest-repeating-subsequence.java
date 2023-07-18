//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String str = br.readLine().trim();
            Solution ob = new Solution();
            int ans = ob.LongestRepeatingSubsequence(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
     public static int solution(String str){
        int[][] dp = new int[str.length() +1][str.length() +1];
        
        for(int i  = dp.length -1; i>=0; i--){
            for(int j=dp[0].length-1; j>=0; j-- ){
                if(i== dp.length -1 && j==dp[0].length -1){
                    dp[i][j] =0;
                }else if(i == dp.length -1){
                    dp[i][j] =0;
                }else if(j == dp[0].length -1){
                    dp[i][j] =0;
                }else {
                    ///either diagonal + one
                    if(str.charAt(i) == str.charAt(j) &&  i != j){
                        dp[i][j]= dp[i+1][j+1] +1;
                    }else{
                    // or max between previous 2
                        dp[i][j] = Math.max(dp[i+1][j], dp[i][j+1]);
                    }
                }
            }
        }
        return dp[0][0];
    }
    public int LongestRepeatingSubsequence(String str)
    {
        return solution(str);
    }
}