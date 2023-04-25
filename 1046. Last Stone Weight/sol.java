class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>();
        for(int stone: stones){
            maxHeap.add(-stone); // flipping the size of all stones
        }
        while(maxHeap.size() >1){
            int stoneOne = -maxHeap.remove();
            int stoneTwo= -maxHeap.remove();
            if(stoneOne != stoneTwo){
                maxHeap.add(-(stoneOne-stoneTwo));
            }
        }
        return maxHeap.isEmpty()?0: -maxHeap.remove(); //flipping the sign again to get the OG back
    }
}
