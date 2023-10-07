//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  bool helper(vector<vector<char>>& board,string word,int i,int j,int n,int m,int k){
        if(k >= word.size())return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.' || word[k]!=board[i][j]) return false;
        if(word.size() == 1 && word[k]==board[i][j]) return true;
        board[i][j] = '.';
        bool temp = false;
        int x[4] = {0,0,-1,1};
        int y[4] = {-1,1,0,0};
        for(int index=0;index<4;index++){
            temp = temp || helper(board,word,i+x[index],j+y[index],n,m,k+1);
        }
        board[i][j] = word[k];
        return temp;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        if(n==0) return false;
        int m=board[0].size();
        if(word.size()==0) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                     if(helper(board,word,i,j,n,m,0))return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends