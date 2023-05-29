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
    void swap(TreeNode root){
        if(root == null){
            return;
        }
        if(root.left != null)
            swap(root.left);
        if(root.right != null)
            swap(root.right);
        if(root.left != null && root.right != null){
            TreeNode temp = root.left;
            root.left = root.right;
            root.right= temp;
        }
        else if(root.left != null && root.right == null){
            TreeNode temp = root.left;
            root.left = null;
            root.right= temp;
        }
        else if(root.left == null && root.right != null){
            TreeNode temp = root.right;
            root.left = temp;
            root.right= null;
        }

    }
    public TreeNode invertTree(TreeNode root) {
        swap(root);
        return root;
    }
}
