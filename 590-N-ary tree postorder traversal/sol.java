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
    public List<Integer> postorder(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        LinkedList<Integer> output_arr = new LinkedList<>();

        if(root == null) return output_arr;

        stack.add(root);
        while(!stack.isEmpty()){
            Node node = stack.pollLast(); // will return the top of the stack
            output_arr.addFirst(node.val); // push to the ans  as before the actual node value 
            for(Node child : node.children){
                stack.add(child);
            }
        }
        return output_arr;
    }
}
