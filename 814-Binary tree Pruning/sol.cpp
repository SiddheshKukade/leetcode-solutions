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
    TreeNode* pruneTree(TreeNode* root) {
        //using post order traversal left right then root
    if(!root) return NULL ; //for exceptional cases
        
    TreeNode *left = pruneTree(root->left);
    TreeNode *right = pruneTree(root->right);
    
    //MAIN OPERATION
    if(root->val==0 and !left and !right) return NULL; // if root value is zero and no left and right nodes present then return NULL
   
    root->left = left; //updating left and right nodes with the actual properties received.
    root->right = right; 
        
    return root; // we are returning root at the end and eliminating zero and null  children 
    }
};
