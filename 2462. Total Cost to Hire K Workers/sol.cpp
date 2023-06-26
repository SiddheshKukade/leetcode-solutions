2462. Total Cost to Hire K Workers
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i = 0;
        int j = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        long long ans = 0;
        while(k--){
            //pushing ele in PQueue
            while(pq1.size() < candidates && i <= j){
                pq1.push(costs[i++]);
            }
            while(pq2.size() < candidates && i <= j){
                pq2.push(costs[j--]);
            }
            //getting the top most element
            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            //check if they match
            if(t1 <= t2){ /// if first one is smaller or equal to second one /// here we are checking the first one to make sure that the index if found
                ans += t1; // add to ans 
                pq1.pop(); // remove that element
            }
            else{ // otherwise.
                ans += t2; // update the answer
                pq2.pop(); // remove that element
            }
        }
        return ans;
    }
};
