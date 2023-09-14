//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& mat) {
    int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                }
            }
        }
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(vis[i][j] == 1){
                    int r = i;
                    int c = j;
                    int dr[] = {0, 1, 0, -1};
                    int dc[] = {1, 0, -1, 0};
                    int sum = 0;
                    for(int k = 0; k<4; k++){
                        int nr = r+dr[k];
                        int nc = c+dc[k];
                        if(nr<row && nr>=0 && nc<col && nc>=0){
                            sum += mat[nr][nc];
                        }
                        
                    }
                    vis[i][j] = sum;
                }
            }
        }
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(vis[i][j] != 0){
                    mat[i][j]=vis[i][j];
                    int r = i;
                    int c = j;
                    int dr[] = {0, 1, 0, -1};
                    int dc[] = {1, 0, -1, 0};
                    for(int k = 0; k<4; k++){
                        int nr = r+dr[k];
                        int nc = c+dc[k];
                        if(nr<row && nr>=0 && nc<col && nc>=0){
                            mat[nr][nc] = 0;
                        }
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends