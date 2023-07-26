class Solution {
//     ///detecting a cycle
//     bool detectCycle(vector<vector<int>> &adj, vector<bool> &visited, int v){
//         if(visited[v] ==1){
//                 return true;
//         }
//         if(visited[v] == 2 ){ // if already processed
//                 return false;
//         }
//         visited[v] =1;
//         for(int i=0; i<adj[v].size(); ++i){
//             if(detectCycle(adj,visited,adj[v][i]))
//                 return true;
//         }
//         visited[v] = 2; // node as processed
//         return false;
//     }
    
    
// //topological sort => dfs+stack
// void dfs(vector<vector<int>> &adj, int v, vector<bool>&visited, stack<int>&mystack){
//     visited[v] = true;
//     for(int i=0; i<adj[v].size(); ++i){
//         if(!visited[adj[v][i]]){
//             dfs(adj,adj[v][i], visited,mystack);
            
//     }
//         //pushing to stack just before backtracking
//         mystack.push(v);       
//     }
// }
    
    
public:
    vector<int> findOrder(int N, vector<vector<int>>& P) {
//         TOPOLOGICAL SORT
//     int n = prerequisites.size();
//     vector<vector<int> >adj(numCourses);
    

//     //make adjacency list
//     for(int i=0; i<n; i++){
//         adj[prerequisites[i][1]].push_back(prerequisites[i][0]);        
//     }
        
//     vector<bool> visited(numCourses, false);
//     vector<int> ans;
//     if(detectCycle(adj,visited,numCourses )) // invalid input
//         return ans; 
    
//     stack<int> mystack;
        
//     //apply dfs
//     for(int i=0; i<numCouses; i++)
//     {
//         if(!visited[i])
//             dfs(adj,i,visited,mystack);
//     }  
        
//     //creating ans list
//     while(!mystack.empty()){
//         ans.push_back(mystack.top());
//         mystack.pop();
//     }
//         return ans;
         vector<vector<int>> G(N);                   // {prerequisite-course : [list of next courses]}
        vector<int> ans, indegree(N);               // indegree[i] denotes number of prerequisite courses for ith course
        for(auto& pre : P) 
            G[pre[1]].push_back(pre[0]),            // forming adjacency list graph
            indegree[pre[0]]++;                     
        
        queue<int> q;
        for(int i = 0; i < N; i++)
            if(indegree[i] == 0) q.push(i);         // we can start with courses having no prequisites
        
        while(size(q)) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);                     // cur has no remaining pre courses, so we can take it now
            for(auto nextCourse : G[cur]) 
                if(--indegree[nextCourse] == 0)     // if there's a next course having 0 prequisite remaining,
                    q.push(nextCourse);             // then we can take it
        }
        if(size(ans) == N) return ans;              // ordering exists where all courses can be finished
        return {};                                      
    }
};