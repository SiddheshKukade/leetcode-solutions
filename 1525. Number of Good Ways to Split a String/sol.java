class Solution {
    public int numSplits(String s) {
        int n = s.length();
        int [] prefix = new int[n];
        int [] suffix = new int[n];
        Set<Character> preSet = new HashSet();
        Set<Character> sufSet = new HashSet();

        for(int i=0; i<n; i++) {
            preSet.add(s.charAt(i));
            sufSet.add(s.charAt(n-1-i));
            prefix[i] = preSet.size();
            suffix[n-1-i] = sufSet.size();
        }
        int goodWays = 0;
        for (int i = 1; i <n ;i++){
            if(prefix[i-1] == suffix[i]){
                goodWays++;
            }
        }
    return goodWays;
    }
}
