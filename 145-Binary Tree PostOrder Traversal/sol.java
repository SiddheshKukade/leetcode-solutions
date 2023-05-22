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
    List<Integer> result ;
    private void post(TreeNode node){
        if(node == null){
            return ;
        }
        if(node.left != null){
           post(node.left);
        } 
        if(node.right != null){
           post(node.right);
         } 
         result.add(node.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
       //left right node
       result = new ArrayList<>();
       post(root);
       return result;
    }
}
