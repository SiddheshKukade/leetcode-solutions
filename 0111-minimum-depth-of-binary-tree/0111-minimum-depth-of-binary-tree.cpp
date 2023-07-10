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
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->right);
        int right =solve(root->left);
        
        return 1 + max(left, right);
    }
    int minDepth(TreeNode* root) {
           if(root == NULL){
            return 0;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(root->left && root->right){
            return min(left+1, right+1);
        }
        return max(left+1, right+1);
    }
};