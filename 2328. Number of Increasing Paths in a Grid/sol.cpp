class Solution {
public:
    int mod= pow(10,9)+7;
    int find(vector<vector<int>> &grid, int i, int j , vector<vector<int>>& dp,int parent){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]<=parent){
            return 0;
        }
        if(dp[i][j] !=  -1){
            return dp[i][j];
        }
        int down = find(grid, i+1, j ,dp, grid[i][j]);
        int up = find(grid, i-1, j ,dp, grid[i][j]);
        int right = find(grid, i, j+1 ,dp, grid[i][j]);
        int left = find(grid, i, j-1 ,dp, grid[i][j]);

        return dp[i][j] = (up%mod+down%mod+left%mod+right%mod+1) %mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(dp[i][j]==-1){
                    find(grid,i,j,dp,-1);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};
