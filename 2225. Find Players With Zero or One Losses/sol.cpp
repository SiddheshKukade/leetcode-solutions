class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> w ,l ; // to store winners and losers in sortted form.
        unordered_map<int, int> tot;

        for(auto it : matches)
            w.insert(it[0]) , l.insert(it[1]) , tot[it[1]]++   ;
    // tot[it[1]]++    == > stores how many time a player has lost
            vector<int> v1, v2;
            vector<vector<int>> ans;
    /// sotring list of players who never lost
            for(auto it: w){
                if(tot.find(it) == tot.end())
                // if we've reached to the end of the list while checking 
                // the winner's loses means that the player has never lost
                  v1.push_back(it);
            }
//  Losers who've exactly lost once.
             for(auto it: l){
                if(tot[it]== 1)
                  v2.push_back(it);
            }
            ans.push_back(v1);
            ans.push_back(v2);

            return ans;
    }

};
