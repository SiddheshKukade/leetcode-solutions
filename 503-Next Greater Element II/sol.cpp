class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
              int n = nums.size();
        vector<int> nge(n , -1);
        stack<int> st;
        
        //checking in reverse with twice the n timems
        for(int i =2*n -1 ; i>=0; i--){
            // if stack is not empty and top list lesser than our element then delete that element from stak 
            while(!st.empty() && st.top() <=nums[i %n]){
                st.pop();
            }
            //if i is still within n and stack is not empty then take the topmost stack as answer
            if(i<n){
                if(!st.empty()) 
                    nge[i] = st.top();
            }
            // we push our answer anyways
            st.push(nums[i%n]);
        }
        return nge; 
    }
};
 
