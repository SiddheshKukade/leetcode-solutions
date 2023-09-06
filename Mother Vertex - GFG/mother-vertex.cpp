//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfs(int vertex, vector<int> adj[], vector<bool>&visited, stack<int> &stk){
        visited[vertex]  =true;
        for(auto node: adj[vertex]){
            if(!visited[node]){
                dfs(node,adj,visited, stk);
            }
        }
        stk.push(vertex); // stack stores all the nodes in dfs order
    }
    bool allVisited(vector<bool>&vis){
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    stack<int> stk;
	    for(int i=0; i<V; i++){
	        if(!vis[i])
	            dfs(i,adj,vis,stk);
	    }
	    int top = stk.top(); // contain the last dfs element
	    for(int i=0; i<V; i++) vis[i] = false; // make all nodes false
	     // call dfs again on the top 
	     dfs(top, adj, vis,stk);
	     // now we check if we could visited all of them via bfs
	     if(allVisited(vis)) return top;
	     return -1;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends