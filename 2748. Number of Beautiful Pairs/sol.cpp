class Solution {
public:
    // bool isNum(){
    //  // coprime gcd is 1
    // ///getting first digit
    //     int f, l, n= nums[i];
    //     l = n % 10 ;
    //     while(n>=10){
    //         n/=10;
    //     }
    //     f= n;
    //     n = nums[i];
    //     if()
    // }
    int countBeautifulPairs(vector<int>& nums) {
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(__gcd(to_string(nums[i])[0]-'0' , nums[j]%10) == 1){
                    ans++;
                }
            }
        } 
        return ans;
    }
};
