class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            if(i%2){ /// odd nos
                ans[i] = ans[i>>1]+1;
            }else{ //// even
                ans[i] = ans [i>>1];
            }
        }
        return ans;

    }
};
