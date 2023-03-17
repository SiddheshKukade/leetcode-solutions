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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int len = inorder.length;
        return helper(inorder, postorder, 0 , len-1, 0 ,len-1);
    }
    private TreeNode helper(int[] inorder, int[] postorder, int inStart,int inEnd, int postStart, int postEnd){
        if(inStart > inEnd){ // if start  overflows the end then return null
            return null;
        }

        int rootVal = postorder[postEnd]; // the last pos of postorder contains the root
        TreeNode root = new TreeNode(rootVal); // creating ndoe to apppend to the answer tree
        int rootIndex = inStart;

        for(; rootIndex<=inEnd;rootIndex++){ // find the matching position of last element of postorder  in inorder
            if(inorder[rootIndex] == rootVal){
                break;
            }
        }
        // Storing the size of the trees.
        int leftTreeSize = rootIndex - inStart; 
        int rightTreeSize = inEnd - rootIndex;
        // call for furthur nodes 
        root.left = helper(inorder, postorder, inStart, rootIndex-1,  postStart, postStart + leftTreeSize - 1);
        root.right = helper(inorder, postorder, rootIndex+1, inEnd, postEnd-rightTreeSize, postEnd -1);
        return root;
    }
}
