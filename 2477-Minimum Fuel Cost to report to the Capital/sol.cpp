class Solution {
public:
    long long  ans;
    long long dfs(vector<vector<int>> &v, int node, vector<int> &vis, int seats){
        vis[node] = true; // make curernt node visited
        long long cnt = 1; // set the count of people to 1 for now
        for(int i=0;i<v[node].size();i++){ // iterate over possible edge nodes for that node
            int curr = v[node][i]; 
            if(!vis[curr]) // check if it was not visited
                cnt += dfs(v,curr,vis,seats); // call dfs on it.
        }

        long long x = cnt / seats ; // no of people / no of seats in car gives us no of cars
        if(cnt %seats) x++; // get the extra car for leftover peple.
        // we've to reach zero 
        // if zero not reached then update the answer;
        if(node !=0) ans +=x; //we've not reached to the end. then update the answer // otherwise no need to increase the cost of trvelling.
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if(roads.size() == 0 )
            return 0;
        ans =0;
        int n = roads.size(); // total no of edges
        vector<vector<int>> v(n+1); // map containing paths of each node
            /// adding the paths
        for(int i =0; i<n;i++){
            int x = roads[i][0] , y = roads[i][1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> vis(n+1, 0);
        //call the dsf with map , 0 as starting point, visted array , no of seats 
        dfs(v,0,vis,seats);
        return ans;
    }
};
