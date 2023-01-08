class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // we can use n square complexity
        // calculating slope of the points and checking them.
        int res =0;
        for(int i=0 ; i<points.size(); i++){
            int duplicate=0;
            unordered_map<double,int> mp;
            double slope =0.0;
            for(int j=0; j<points.size(); j++){
            int x1 = points[i][0];
            int x2 = points[j][0];

            int y1 = points[i][1];
            int y2 = points[j][1];

            int dy = y2-y1;
            int dx= x2-x1;

            if(dy==0 && dx ==0 ){
                duplicate++; // duplicate points are pts having same coordinates twice
                continue;
            }
            if(dx !=0){
                slope = dy*1.0/dx ; // converting into double my multipying with 1.0 to get exact values
            }else{
                slope = INT_MAX;
            }
            mp[slope]++; // increment no of points present for that slope
            }
            if(mp.size() ==0)
                res=duplicate; 
            else{
                for(auto slope:mp){
                    res= max(res,slope.second+duplicate);
                }
            }
        }
        return res;
    }
};
