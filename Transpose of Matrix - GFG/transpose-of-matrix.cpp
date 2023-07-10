//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        // vector<vector<int>> t(3,vector<int>(3));
        std::vector<std::vector<int>> t(n, std::vector<int>(n));
        for(int i=0; i<n ;i++){
            for(int j=0; j<matrix[0].size();j++){
                t[i][j] = matrix[j][i];
            }
        }
        matrix =t;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n,vector<int>(n)); 

        for(int i=0; i<n; i++)
        {
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.transpose(matrix,n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends