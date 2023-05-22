/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        while(!queue.isEmpty()){
            root = queue.poll(); //prints the head and deletes the head.
            if(root.right != null){ // firsly traversing all the right ele
                queue.offer(root.right);
            }
            if(root.left != null){  // now traversing left elements 
                queue.offer(root.left);
            }
        }
        /// after following this left and right methods in the end we will have the 
        /// left nodes in the end and the leftest is at the end of the queue 
        // / so it's the answer in the end
    return root.val;
    }
}
