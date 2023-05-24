// TIME N LOG N
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        multimap<int,int> m;
        for(int i=0;i<n;++i)
            m.insert({points[i][0] * points[i][0] +  points[i][1]* points[i][1], i }); // stores in sorted manner
 
        vector<vector<int>> ans;
        int count =0;

        for(auto i=m.begin(); count<k;++count, ++i){
            ans.push_back(points[i->second]);
        }
        return ans;
    }
};
