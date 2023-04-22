class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       //just count the values of inner vectors return the max sum 
       int maxWealth = 0;
       int rows = accounts.size();
       int cols = accounts[0].size();

       for(int i=0;i<rows;i++){
        int wealth =0; // set to zero
        for(int j=0; j<cols;j++){ // interate over all inner array.
            wealth+= accounts[i][j];  //total wealth
        }
        maxWealth = max(maxWealth, wealth);
       } 
       return maxWealth;
    }
};
