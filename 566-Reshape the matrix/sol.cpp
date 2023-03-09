class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r,vector<int>(c));
        if(mat.size() * mat[0].size() != r*c) // if element can be fited or not 
        {
            return mat; // RESHAPE NOT POSSIBLE;
        }
        int row =0;
        int col = 0;
        for(int i=0; i<mat.size();i++){
            for(int j=0; j<mat[0].size(); j++){
                ans[row][col] = mat[i][j];
                col++; //inversely incrementing cols instead of row
                if(col == c){ // if col reaches to limit
                    row ++; 
                    col=0;
                }
            }
        }
        return ans;
    }
};
