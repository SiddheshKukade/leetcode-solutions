class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
     List<Integer>[] g = new ArrayList[n];
     //creting a new arrayList for each element
     for(int i =0; i<n;i++){
         g[i] = new ArrayList();
     }
     //for storing their indegree
     int[] inDegree = new int[n]; // auto initialized by 0 zero
     for(List<Integer> e:edges){
         //iterater over each edge
         //store theier combination in proper locations
         g[e.get(0)].add(e.get(1));
         //increase the counter of inDegree of the second edge
         inDegree[e.get(1)]++;
     }
      for(List<Integer> e:edges){
         System.out.println(inDegree[e.get(1)]);
     }
    //  for storing the result
     List<Integer> result = new ArrayList();
    for(int i=0;i<n;i++){ // iteratingg over totla edges 
             if(inDegree[i]==0)
                result.add(i);
     }
     return result;
    }
}
