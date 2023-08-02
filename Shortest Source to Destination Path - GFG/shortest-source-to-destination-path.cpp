//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
             // code here
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        while(q.size() != 0)
        {
            auto temp=q.front();
            q.pop();
            int dis=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;
            if(i==X && j==Y)
                return dis;
            for(int k=0;k<4;k++)
            {
                int new_row=i+drow[k];
                int new_col=j+dcol[k];
                if(new_row>=0 && new_col>=0 && new_row<N && new_col<M && A[new_row][new_col]==1)
                {
                    A[new_row][new_col]=0;
                    q.push({dis+1,{new_row,new_col}});
                }
            }
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends