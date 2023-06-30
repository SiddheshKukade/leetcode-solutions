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
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            v.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        map<int,int> m ;
        for(int i=0; i<v.size(); i++) m[v[i]]++;

        vector<pair<int,int>> v1;
        vector<int> ans;
        for(auto it: m){
            v1.push_back({it.second, it.first}); // adding count as first here.
        }
        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());
        int l = v1[0].first;
        for(int i=0; i<v1.size(); i++){
            if(l==v1[i].first){
                ans.push_back(v1[i].second);
            }
        }
        return ans;
    }
};
