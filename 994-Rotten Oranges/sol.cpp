class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //using Bredth First Search Technique
        //using a queue Data Structure
        /* insert the rotten oranges in queue and check it's count */
        if(grid.empty()) return 0;
        
        int m = grid.size(), n =grid[0].size() , days=0, tot=0, cnt=0;
        queue<pair<int , int>> rotten;
        for(int i=0 ;i<m;i++){
            for(int j=0 ;j<n;j++){
                if(grid[i][j] !=0) tot++; // storing total count of oranges
                if(grid[i][j] == 2) rotten.push({i,j}); // save the rotten
                }
        }
        //to travese in 4 directions
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;
            while(k--){ // untill the rotten count
                int x = rotten.front().first ,y = rotten.front().second;
                //x and y have firrst 2 rotten
                rotten.pop(); // deleted the first
                for(int i=0 ; i<4;++i){// traverse in direction and pushes the rotten oranges 
                    int nx = x + dx[i] , ny = y + dy[i];
                    //if they are less than zero(empty space no oranges) not a beyond m and n sizes and aren't fresh skip them 
                    if(nx < 0 || ny<0 || nx>=m || ny >=n || grid[nx][ny] != 1 ) continue;
                    grid[nx][ny] = 2; // mark as rotten
                    rotten.push({nx,ny}); // push to orange list 
                    // days++;
                }
            }
            if(!rotten.empty()) days++;
        }
        return tot == cnt ? days : -1 ;
    }
};
