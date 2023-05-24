class Solution {
    public String reorganizeString(String s) {
                ///MAX HEAP
        Map<Character, Integer> counts = new HashMap<>();
        for(char c:s.toCharArray()){
            counts.put(c, counts.getOrDefault(c,0) +1);/// storing the occurences  of chars
        }
        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a,b)-> counts.get(b) - counts.get(a));
        // just like js array.filter method
       ///storing the count of a and b 
        maxHeap.addAll(counts.keySet());


        StringBuilder result = new StringBuilder();

        //GREEDY APPROACH
        while(maxHeap.size() > 1){ // 

            ///curr and next are most freqently used chars
            char current = maxHeap.remove();
            char next = maxHeap.remove();
            result.append(current);
            result.append(next);

            counts.put(current, counts.get(current)-1);
            counts.put(next, counts.get(next)-1);

            if(counts.get(current)> 0){
                maxHeap.add(current);
            }

            if(counts.get(next)> 0){
                maxHeap.add(next);
            }
        }

    if(!maxHeap.isEmpty()){  //// if still not empty and last elements is present
        char last = maxHeap.remove();
        if(counts.get(last)> 1){
               return ""; // can't insert 
            }
        result.append(last);
    }
    return result.toString();
    }
}
