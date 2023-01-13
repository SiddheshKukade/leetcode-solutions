class Solution {
public:
        // int res=0;
    int longestPath(vector<int>& parent, string s) {
        //use the implementation of the graph.
        //don't get confused due to the tree in the input image. ;-)
        int n = s.size(),res=0;
        vector<vector<int>> children(n, vector<int>());

        for(int i=1; i<n; i++){
            children[parent[i]].push_back(i);
        }
        dfs(children,s,res,0);
        return res;
    }
    int dfs(vector<vector<int>> & children, string &s, int &res , int i){
        int big1=0;
        int big2=0;
        for(int &j: children[i]){
            int cur = dfs(children,s,res,j);
            if(s[i] == s[j]) continue; // checking character here
            if(cur>big2) big2=cur;
            if(big2 > big1) swap(big1, big2);
        }
        res = max(res, big1+big2+1);
        return big1+1;
    }
};
