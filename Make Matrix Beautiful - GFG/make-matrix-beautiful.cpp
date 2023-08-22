//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rows(n);
        int need = 0;
        for(int i=0; i<n; i++){
            int row, col;
            row = col=0;
            
            for(int j=0; j<n ; j++){
                row += matrix[i][j];
                col += matrix[j][i];
            } // getting the total of curr row and col
            need = max({need, row ,col}); // getting the max of currmax, currrow, and currcol
            rows[i] = row; /// storing the values[i] as rows
            ///we can also do rows[i] = col it does not matter.
        }
        int ans =0;
        for(auto row: rows){
            ans += need - row;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends