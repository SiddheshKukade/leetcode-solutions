class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k) {
        //using prefix sum array to find the diameter difference
        int n = v.size();
        long long int pre[n], suff[n];
        pre[0] = v[0];
        // prefix arr
        for(int i=1; i<n;i++){
            pre[i] = pre[i-1] + v[i];
        }
        suff[n-1]=v[n-1];
        // suffix arr
        for(int i=n-2; i>=0; --i){
            suff[i] = suff[i+1] + v[i];
        }
        vector<int> ans;
        for(int i=0; i<n; ++i){
            if(i-k<0 || i+k>=n){
                ans.push_back(-1);
            }else{
                //formula to get the diamter sum
                                                    /// left side           ///right side /// curr element
                long long int sum = (long long int)((suff[i-k]-suff[i])+ (pre[i+k]-pre[i])+v[i]);
                sum = sum / (2*k+1); // this is subarray average
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
