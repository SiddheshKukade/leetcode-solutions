class Solution {
public:
    bool isSafe1(int row , int col , vector<string> board ,int n ){
        //check that the queen at the given row and column will no be killed by the any other queen present in the other columns
        //check on left  indexes for the queen positions
        // a we are vchecking from left to right and queens from the right have still not moved.
        int duprow = row ;
        int dupcol = col;
        
        while(row >= 0 && col>=0){
            if(board[row][col] == 'Q') return false; 
            row--; // upper diagonal check
            col--;
        }
        col = dupcol;
        row=duprow;
        while(col>=0){
            if(board[row][col] == 'Q') return false; 
            col--;// horizhontal check 
        }
        col = dupcol;
        row=duprow;
        
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++; // donwnward diagonal check
            col--;
        }
        return true; //if q was not present in the previous 3 diganoal postions on the left side then we can sucessfully place our queen here
    }
    void solve(int col , vector<string>&board , vector<vector<string>> &ans, int n){
        if(col == n){ // we have completed moves for all the queens
            ans.push_back(board); // save the current compute combination to the answer array
            return;
        }
        for(int row =0 ; row<n;row++){
            if(isSafe1(row, col, board , n )){ // if safe to be moved means it will no be kiled by other queen for this poisition
                board[row][col] = 'Q';
                solve(col+1, board , ans , n ); // check for the next queen
                board[row][col] ='.'; // backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n); // array of size N containing string board ["", ""]
        string s (n ,'.');// string of size n and contains only . so "...." for n=4
        for(int i=0 ; i<n ; i++){
            board[i] = s ; // insert it n times in our array;
        }
        solve(0 , board , ans, n); // call the function starting with column 0
        return ans;
    } 
};
