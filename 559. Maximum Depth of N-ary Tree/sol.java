/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public int maxDepth(Node root) {
        //BFS
        if(root == null) return 0;
        int depth =0; 
        Queue<Node> queue = new LinkedList();
        queue.offer(root);
        while(!queue.isEmpty()){
            int size = queue.size();

            for(int i=0; i<size; i++){ // iterate over all current ele of the q
                Node currentNode = queue.poll();
                for(Node child: currentNode.children){
                    queue.offer(child); // insert connections back in the queuee
                }
            }
            depth++;
        }
        return depth;
    }
}
