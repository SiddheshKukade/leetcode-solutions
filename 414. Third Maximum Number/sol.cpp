class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> st;
        for(int n : nums){
            st.insert(n);
        }
        /// [1,2] => [2,1]
        if(st.size() < 3){ return *st.begin();}
        int itr=1 , ans;
        for(auto i: st){
            if( itr == 3) ans =i;
            itr++;
        }
        return ans;

    }
};
