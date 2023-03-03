class Solution {
public:
    double average(vector<int>& salary) {   
        int maxi = 0;
        int small = INT_MAX;
        double sum = 0;
        for(int i=0; i<salary.size(); i++){
            maxi = max(maxi, salary[i]);
            small = min(small , salary[i]);
        }
           for(int i=0; i<salary.size(); i++){
           if(salary[i] != maxi && salary[i]!= small){
            sum += salary[i];

           }
        }
        // cout<<maxi<<"  "<<small;
        // sum =sum-  maxi;
        // sum = sum- small;

        return double(sum/( salary.size()-2));
    }
};
