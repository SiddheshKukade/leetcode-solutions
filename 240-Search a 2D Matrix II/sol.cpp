    class Solution {
    public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         // start from diagonal 2 poitns 
         int row =0  , column = matrix[0].size()-1 ;//to get last element of the row
        while(row< matrix.size() &&column>=0){ // make sure we are in matrix
            if(matrix[row][column] == target) return true;// if we  found target
            //VERY IMPORTANT CONDITIONS 
                // target > pivot -> r++ // go to next row
                // target < pivot -> c--; // go backwards on same row
            else if  (matrix[row][column] < target) row ++; // 
            else column --;
              }
         return false;
         }  
    };

// TIME LIMIT EXCEEDED 
 // bool searchMatrix(vector<vector<int>>& matrix, int target) {
 //        for(int i =0; i<matrix.size();i++){
 //            for(int j =0; j<matrix[i].size();j++){
 //                if(matrix[i][j] == target) {
 //                    return true;
 //                }               
 //            }
 //        }
 //        return false;
 //    }
