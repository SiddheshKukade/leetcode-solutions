class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        //firsrt sort the array ;
        //check one by one if the double value exists or not 
        int n = changed.size();
        if(n%2 == 1) return {};
        sort(changed.begin() , changed.end());
        vector<int> ans;
        map<int,int> mp;
        for(int i=0 ; i<n ;i++){
            mp[changed[i]]++;
        } // getting the frequency of all elements
        for(int i=0 ; i<n;i++){
            if(mp[changed[i]] ==0) continue; // if curr freq is 0 then skip
            if(mp[changed[i]*2]  ==0) return {}; //if freq of current's *2 number is zero then {}
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2] --; //reducing the freq of both curr no and *2 number
        }
        return ans;
    }
};
