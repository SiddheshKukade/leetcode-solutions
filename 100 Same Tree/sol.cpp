class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p  && !q){ // if both don't exists that means we can set them as the same
            return true;
        }
        if((!p || !q) || (p->val != q->val)){ // if p or q doesn't exists OR if therir values are not matching then we return false
            return false;
        }
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); //checking on left and right side recursively
    }
};
