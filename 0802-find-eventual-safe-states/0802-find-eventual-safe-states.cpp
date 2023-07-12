class Solution {
public: 
    bool DFSRec(int s ,vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int>>&graph,
               vector<bool> &present_cycle){
        ///s is source
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int> data= graph[s]; // adjancet 
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x,visited,dfsVisited,graph, present_cycle)){
                    return present_cycle[s] = true;
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return  present_cycle[s]=true;
            }
        }
        dfsVisited[s] = false;
        return false;
        
        
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<bool> present_cycle(n,false);
        vector<bool> visited(n, false), dfsVisited(n ,false);
        for(int i=0; i<n; i++){
                if(!visited[i]){
                    DFSRec(i, visited, dfsVisited,graph,present_cycle);
                }
        
        }
        for(int i=0; i<n;i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }   
        }
        return ans;
    }
};