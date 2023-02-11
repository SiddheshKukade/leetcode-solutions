class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dis(n, -1);
        vector<pair<int,int>>adj[n+1];

        for(auto vec: redEdges){
          adj[vec[0]].push_back({vec[1], 1});  
        }

        for(auto vec: blueEdges){
          adj[vec[0]].push_back({vec[1], 2});  
        }
        queue<vector<int>>q;
        // gtom where , distance ,which edge
        q.push({0,0,-1});
        while (q.size ()> 0){
             auto  currVec = q.front();
             q.pop();
             int currV = currVec[0],edgeColor= currVec[2];
             if(dis[currV] == -1){
                 dis[currV] = currVec[1];
             }
             for(auto &childPair: adj[currV]){
                 int childV = childPair.first, edgeColorOfChild = childPair.second;
                 if(childV != -1 && (edgeColor == -1 || edgeColor != edgeColorOfChild)){
                     q.push({childV, currVec[1]+1, edgeColorOfChild});
                     childPair.first = -1;
                 }
             }
        }
        return dis;
    }
};
