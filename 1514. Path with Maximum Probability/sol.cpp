class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        ///Brute calc all the path with max prob for each node.
    //    The graph is represented using an adjacency list, where each node is associated with a list of its neighboring nodes and their corresponding success probabilities.
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v= edges[i][1];
            adj[u].push_back({v, succProb[i]}); // adding ref of v on u
            adj[v].push_back({u, succProb[i]}); // adding ref on u on v
        }
     
        // If the new probability is greater than the current probability stored in the distance array for the neighbor, update the distance array with the new probability and enqueue the neighbor to continue the BFS traversal.
        vector<double> dist(n,0.0);
        dist[start] = 1.0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            for(auto x: adj[curr]){ // checking the adjacent element of curr node.
                int node = x.first; 
                double prob =  x.second;
                double newProb = dist[curr] * prob;

                 if (newProb > dist[node]) {
                     dist[node] = newProb;
                     q.push(node);
                 }
            }
        }
        return dist[end];
    }
};
