class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //setting entire row to zero
            // means iterating over [i][j] j and keeping i constant.
        // setting entire column to zero
            // iterating over [i][j] i keeping j constant.
        int row =0;
        int column=  0;
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> cols;
        set<int> rows;
        for(int i=0; i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] ==0){
                     rows.insert(j);
                     cols.insert(i);
                }
            }
        }
        int count =0;
          for(int i=0; i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if (rows.count(j) || cols.count(i)  ){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
