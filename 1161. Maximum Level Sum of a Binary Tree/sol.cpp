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
   
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int ans=0;
        int maxi = INT_MIN;
            int level = 0;
        while(!q.empty()){
            int size= q.size(), sum=0;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                sum += cur->val;
                q.pop();
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                } 
        }
        level++;
        if(sum > maxi){
            ans=level;
        }
         maxi = max(maxi , sum  );
    }
    return ans;
    }
};
