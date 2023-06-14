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
    public int getMinimumDifference(TreeNode root) {
        /// the difference has to be found between the values of the nodes and not between their paths from one another
        Stack<TreeNode> st = new Stack<>();
        TreeNode curr = root;
        TreeNode prev = null;

        int res = Integer.MAX_VALUE;
        while(curr != null || !st.isEmpty()){
            if(curr != null){
                st.push(curr); /// keep pushing new elements in stack
                curr = curr.left; // move to the left
            }else{
                curr = st.pop();
                if(prev != null ) res = Math.min(res, curr.val-prev.val);
                prev = curr;
                curr = curr.right; // if null then move to right;
            }
        }
        return res;
    }
}
