class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row , int col , char c){
        // this function just check all the rules of sudoku for the current positon and number
    //sudoku conditions 
        /* 1 : all numbers must be unique in the row w
           2 : all numbers must be unique in the column 
           3 : sudoku is again broken into 3x3 matrix and each 3x3 matrix should not contain any duplicate numbers*/
        for(int i=0 ; i<9; i++){ // iterating over entire board to check
            if(board[i][col] ==c) // 
                return false;// checking the current row iteratively to find the duplicate
            if(board[row][i] ==c)
                return false; //checking the current column iteratively to find the duplicate
            if(board[3*(row/3) + i/3] [3*(col/3) + i%3] == c)
                return false;// checking for the 3x3 matrix
            // row [3*(row/3) + i/3]
            //ex .( 3 * (5/3)  )+ 0/3 = 3;
            // EXAPLAINATION FOR ROWS
            //(row/3) breaks down all the rows in 3 groups 
            // group 1 having ans 0 is => 0 1 2 
            // group 2 having ans 1 is => 3 4 5 
            // group 3 having ans 2 is => 6 7 8  
            // multiplying with 3 again returns the orginal number for that 
            // so 3*(row/3) only gives values in starting point for the 3x3 matrix ex. 0 3 6 
            // then i/3 will be used to keep going 0 1 2  over the rows
            //output will be 000 111 222 // used to check 3 times over that columns
            // EXPLAINATION FOR COLUMN
            //(3*(col/3)) ==> already explained above but here this will return the starting poistion for the curerent column 
//             which would be again any one of 0 3 6
            // i%3 is used after wards givs ans like 1 2 0 (Notice the differece that is is 1 2 0 iterations // outputs for i%3 will be 012 012 012 
            //col  [3*(col/3) + i%3] 
            // ex. [(3* 7/3  )+0/3 ] =6;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i=0 ; i< board.size(); i++){ // traverse over the entire matrix
            for(int j=0 ; j<board[0].size(); j++){
                if(board[i][j] == '.'){ // if the current pos is empty
                    for(char c ='1'; c<='9' ;c++){ // from 1  to 9 
                        if(isValid(board ,i,j,c)){ // check if the same number is not in the current row & column & and It's 3x3 Matrix
                            board[i][j]=c; // fill the current number
                            if(solve(board) == true)
                                return true; // if current number is okay just keep returning true and keep calculating the furthur numbers
                            // This doesn't remove the current answer form the board
                            else 
                                board[i][j]='.'; // removing the current number as due ti that we couldn't fill the furthur numbers along the way in the recursion tree
                        }
                    }
                    return false;  // if we could not fill any number furthur if due to previous combinations so the for loop calls are not executed and after that false we are making that place non filled again
                }
            }
        }
        return true; // if we've sucessfully traversed the entire board then we can sucessfully return true at the end
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // calling the solve function
    }
};
