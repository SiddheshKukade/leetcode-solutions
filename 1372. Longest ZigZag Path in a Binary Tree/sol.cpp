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
    int maxi=0; //
    void rec(TreeNode* root, int dir, int len){
        if(root==NULL) return;
        maxi=max(maxi,len);
        if(dir == 0){
            rec(root->left, dir, 1); // if same direction the start again from length 1
            rec(root->right, dir^1, len+1); //inverting the direction using ^ with length++
        }else{
            rec(root->left, dir^1, len+1); //inverting the direction using ^ with length++
            rec(root->right, dir, 1);// if same direction the start again from length 1
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        rec(root->left, 0,1); 
        rec(root->right,1,1);
        return maxi;
    }
};
