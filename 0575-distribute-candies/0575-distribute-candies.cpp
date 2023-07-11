class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(int i: candyType){
            st.insert(i);
        }
        int ans=0;
        for(auto i: st){
            ans++;
        }
        if(ans > candyType.size()/2)
            return candyType.size()/2;
        return ans;
    }
};