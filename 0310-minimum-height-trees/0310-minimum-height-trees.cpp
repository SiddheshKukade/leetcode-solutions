class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
           if(n==0) return {};
        if(n==1) return {0};
        if(n==2) return {0,1};
        
        
           vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        vector<int> res;
        ///creating adj list and increasing degree 
                for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
         queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
          while(!q.empty()) {
            res.clear();
            int sz = q.size();
            
            while(sz--) {
                int u = q.front();
                q.pop();
                res.push_back(u);

                for(auto v: graph[u]) {
                    if(--degree[v] == 1) 
                        q.push(v);
                }
            }
        }
        return res;
    }
};