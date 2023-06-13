class Solution {
    public int equalPairs(int[][] grid) {
    ///Brainstoriming
    /// create a string for all the pairs and then check if the strings are matching as a pair and keep increasing the count 
    // storing theses values as a hashmap
    int n = grid.length;
    int ans =0;
    Map<String , Integer> rowHash = new HashMap<>();
    Map<String , Integer> colHash = new HashMap<>();

    for(int[] row: grid){
        StringBuilder sb = new StringBuilder();
        for(int i : row){
            sb.append(i).append("#");
        }
        rowHash.put(sb.toString(), rowHash.getOrDefault(sb.toString(), 0) +1);
    }

    for(int j=0; j<n; j++){
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++){
            sb.append(grid[i][j]).append("#");
        }
        colHash.put(sb.toString(), colHash.getOrDefault(sb.toString(), 0) +1);
    }
    for(Map.Entry<String ,Integer> entry: rowHash.entrySet()){
        String rHash = entry.getKey();
        if(colHash.containsKey(rHash)){
            ans += colHash.get(rHash) * rowHash.get(rHash);
        }
    }
    return ans;
       
    }
}
