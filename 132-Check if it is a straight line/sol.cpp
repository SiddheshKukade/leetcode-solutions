class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cdn) {// short for co-ordinates
        int points = cdn.size();
        int xdiff = abs(cdn[1][0] - cdn[0][0]);
        int ydiff = abs(cdn[1][1] - cdn[0][1]);
        int curr_xdiff, curr_ydiff;
        for(int i =2; i<points; ++i){ // loop untill end starting from 2nd point
            curr_xdiff  = abs(cdn[i][0] - cdn[i-1][0]);
            curr_ydiff =  abs(cdn[i][1] - cdn[i-1][1]);
            if(ydiff*curr_xdiff != xdiff*curr_ydiff) {// if the slopes are no the same as the previous ones.
                return false;}
        }
        return true;
    }
};
