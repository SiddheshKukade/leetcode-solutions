class Solution {
public:
    int fin;
    vector<int> loc;
    int dp[205][205]= {0};

    int solve(int idx, int fuel){
        int ans =0;
        if(idx == fin){
            ans++;
        }
        if(dp[idx][fuel] != -1){
            return dp[idx][fuel];
        }

        for(int i=0; i<loc.size(); i++){
            if( i!= idx && abs(loc[i]- loc[idx])<= fuel){
                ans += solve(i, fuel-abs(loc[i]-loc[idx]));
                ans %= 1000000007;
            }
        }
        return dp[idx][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        ///keep driving untill you have fuel and count how many times you have pass the city;
        ///Array Dynamic Programming  Memoization
        fin = finish; 
        loc = locations;
        memset(dp , -1, sizeof(dp));
        return solve(start, fuel);
    }
};
