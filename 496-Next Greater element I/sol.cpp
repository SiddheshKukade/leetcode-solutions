class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int> st;

        int n = nums2.size();
        for(int i = n-1; i>=0; i--){
            int ele = nums2[i]; //
            while(!st.empty() && st.top() <= ele){ //unrill stack is not empty and topmost ele is less than or equal to first element. 
                st.pop(); // delete all the smallers ele than current  ele.
            }
            int res = (st.empty()) ? -1: st.top(); // check the ans if found or -1
            umap.insert({ele,res}); // creating a referencce map to find out the answers
            st.push(ele); // push that on stack to check further
        }
        // inserting elements in answer
        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(umap[x]);
        }
        return ans;
    }
};
