class Solution {
    vector<int> ans;
public:
void fun(TreeNode* root){
    if(root){
        ans.push_back(root->val);
        fun(root->left);
        fun(root->right);
    }
}
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder traversal  root left right
        fun(root);
        return ans;
    }
};
