class Solution {
public:
int n ;
// int t[21][5001][5001]; */// space exceeded stack oerrflow.
///offside addition to avoid overflow
int t[21][10003];
    int solve(vector<int>&rods,  int idx, int diff){
        if(idx >= n){
            if(diff == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(t[idx][diff +5000]!=-1){
            return t[idx][diff+5000];
        }
        ///no taking rods
        int nothing = solve(rods, idx+1,diff);
        /*//taking rod 1*/
        int left_rod=rods[idx]+ solve(rods, idx+1, diff+rods[idx]);
        //taking right rod
        int right_rod= rods[idx]+solve(rods, idx+1,  diff-rods[idx]);
        return t[idx][diff+5000]= max({nothing, left_rod, right_rod});
    }
    int tallestBillboard(vector<int>& rods) {
            // Array
            // Dynamic Programming
            // just have to find disjoint sets having a common sum no 
            // need to use all the elements see ex.02
       n = rods.size();
       memset(t,-1,sizeof(t));
       return solve(rods,0,0)/2; 
    }
};
