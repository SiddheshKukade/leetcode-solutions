class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // using the nCr formula from maths.
        // Time complexiry is O (n)
        //space O(n2)
        vector<vector<int>> r(numRows);
        for(int i=0; i<numRows ; i++){
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1; //first and last element are always one

            for(int j=1; j<i; j++){
                // current ele = last ele of that column +  
                r[i][j] = r[i-1][j-1] + r[i -1][j];
            }
        }
        return r;


    }
};
