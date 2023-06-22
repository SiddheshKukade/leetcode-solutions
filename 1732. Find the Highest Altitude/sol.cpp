class Solution {
public:
    int largestAltitude(vector<int>& gain) {
     int pos =0;
     int maxi=0;
     for(int i=0; i<gain.size(); i++){
         pos+= gain[i];
         maxi = max(maxi,pos);
     }
     return maxi;   
    }
};
