class Solution {
public:
    vector<int> ans;
    vector<vector<int>> graph;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        graph.resize(n, vector<int>{});

        for(auto it:edges){
            graph[it[0]].push_back(it[1]); 
            graph[it[1]].push_back(it[0]);
        }
        dfs(0,-1, labels);

        return ans;
        
    }
    vector<int> dfs(int s ,int par, string &labels ){
        vector<int> res(26,0); // contains 26 alphabets
        res[labels[s]-'a']++;

        for(int it:graph[s]){
            if(it == par){ // bypass  parent
                continue;
            }
            vector<int> f = dfs(it,s,labels);
            for(int i=0; i<26; ++i){
                res[i] +=f[i]; // update res with new frequencies.
            }
        }
        ans[s] = res[labels[s]-'a'];
        return res;
    }
};
