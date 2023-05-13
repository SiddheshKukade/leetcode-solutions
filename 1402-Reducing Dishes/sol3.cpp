class Solution {
public:

      int solveTab3(vector<int>& sat){
        int n =sat.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        for(int i = n-1; i>=0;i-- ){
            for(int time = i; time>=0 ;time--){
                 int include = (sat[i] * (time+1)) + next[time+1];
                 int exclude = 0 +  next[time];

                 curr[time] = max(include,exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());         
        return solveTab3(satisfaction);
    }
};
