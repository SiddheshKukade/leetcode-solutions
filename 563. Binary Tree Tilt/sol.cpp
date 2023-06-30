/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result =0;
    int helper(TreeNode* node){
        int left = (node->left ? helper(node->left): 0);
        int right = (node->right ? helper(node->right): 0);
        result += abs(right - left); // storing the overall total
        return left + right + node->val;
    }
    int findTilt(TreeNode* root) {
        ///returning the sum of the root node only 
        if(root) helper(root); /// calcing the result 
        return result;
    }
};
