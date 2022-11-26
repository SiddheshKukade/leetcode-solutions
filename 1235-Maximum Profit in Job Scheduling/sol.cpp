class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        int dp[n];
        // a list stores , ending time , pair of starting time and profit
        vector<pair <int ,pair<int,int>>> y(n); 

        //inserting the given values in our vector
        for(int i=0; i<n; i++){
            y[i].first = endTime[i];
            y[i].second.first = startTime[i];
            y[i].second.second = profit[i];
        }

        //sorting the given input as per the ending time
        sort(y.begin(), y.end());

        //actual logic
        for(int i=0 ; i<n ; i++){
            if(i==0){ // for the very first jon
                dp[i]  = y[i].second.second; // store the profit
                continue; // skip everything else
            }
        
            int f=0; // stores the current profit
        for(int j = i-1; j>=0; j--){ // going backwards to check for better profit
            if(y[j].first <= y[i].second.first){ // if any ending time is lesser than the arrival time 
                f = dp[j]; 
                break;
            }
        }
        dp[i] = max(dp[i-1] , f+y[i].second.second); // only accept profit if it's greater than current profit.
        }
        return dp[n-1]; // send the last profit which is the highest o
        
    }
};
