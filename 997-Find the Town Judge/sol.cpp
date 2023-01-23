class Solution {
    public int findJudge(int N, int[][] trust) {
       int[] count = new int[N+1];
       for(int[]t :trust){
           count[t[0]]--; // it's it's trusting someone decrement it's score
           count[t[1]]++; // if prople are trusting it then increment it
       }
       for(int i=1;i<=N;i++){
           if(count[i]== N-1) return i;
       }

       return -1;
    }
}
