 void findCombination(int ind , int target ,  vector<int> &arr , vector<vector<int>> &ans ,          vector<int> &ds){
            if(target ==0){ // if combo is found the add to ans array 
                ans.push_back(ds);
            return ; // close the current function call
            }

        for(int i= ind; i<arr.size() ; i++){ 
            /// iterate over entire array starting from current index
            if(i > ind && arr[i] == arr[i -1 ]) continue; 
// if the current and previous element are same and it's not the first time checking this 
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            
            findCombination(i+1 , target- arr[i] , arr ,ans ,ds);
            ds.pop_back();
        }
      
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //two approcahes one is pick & non pick method
        // time complexity => 2 ^ n * K 
        // space complexity => K * X (x is no of combinations)
        vector<vector<int>> ans;
        vector<int> ds ;
        sort(candidates.begin(), candidates.end());// sorting the given array
        findCombination(0 , target, candidates , ans, ds);
        return ans;
    }
};
