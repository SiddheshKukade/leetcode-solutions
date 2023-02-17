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
    // TC O(n) SC O(1) 
    int result = Integer.MAX_VALUE;
    TreeNode prev = null;
    private void inorder(TreeNode root){
        if(root==null){
            return;
        }
        inorder(root.left);
        if(prev !=null){
            result = Math.min(result , root.val - prev.val);
        }
        prev = root ;
        inorder(root.right);
    }
    public int minDiffInBST(TreeNode root) {
        inorder(root);
        return result;
    }
}
