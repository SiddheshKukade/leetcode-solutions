//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool helper(vector<vector<char>>&grid,int i, int j,string word, int idx, int type){
          int n=grid.size();
        int m=grid[0].size();
        int size=word.size();
        if(idx>=size)
        return true;
        
        if(i<0||i>=n||j<0||j>=m)
        return false;
        
        while((i>=0&&i<n)&&(j>=0&&j<m)){
            if(idx>=size)
            return true;
            
            if(grid[i][j]!=word[idx])
            return false;
            
            if(type==1){
                i--;
            }
            else if(type==2){
                i++;
            }
            else if(type==3){
                j--;
            }
            else if(type==4){
                j++;
            }
            else if(type==5){
                i--;
                j--;
            }
            else if(type==6){
                i--;
                j++;
            }
            else if(type==7){
                i++;
                j--;
            }
            else if(type==8){
                i++;
                j++;
            }
            idx++;
        }
         if(idx>=size)
            return true;
            
        return false;
    }
    bool solve(vector<vector<char>>&grid,int i, int j,string word, int idx){
        int n=grid.size();
        int m=grid[0].size();
        int size=word.size();
        if(idx>=size)
        return true;
        
        if(i<0||i>=n||j<0||j>=m)
        return false;
        
        
        if(grid[i][j]==word[idx]){
            bool up=helper(grid, i-1, j, word, idx+1,1);
            bool down=helper(grid, i+1, j, word, idx+1,2);
            bool left=helper(grid,i,j-1,word,idx+1,3);
            bool right=helper(grid,i,j+1,word,idx+1,4);
            bool lu=helper(grid,i-1,j-1,word,idx+1,5);
            bool ru=helper(grid,i-1,j+1,word,idx+1,6);
            bool ld=helper(grid,i+1,j-1,word,idx+1,7);
            bool rd=helper(grid,i+1,j+1,word,idx+1,8);
            
            return up||down||left||right||lu||ru||ld||rd;
        }
        else
        return false;
    }
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        // Code here
        vector<vector<int>>ans;
        
        int n=grid.size();
        int m=grid[0].size();
        int size=word.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]&& solve(grid,i,j,word,0)){
                    ans.push_back({i,j});
                }
            }
        }
        if(ans.size()==0)
        ans.push_back({-1});
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends