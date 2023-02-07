class Solution {
public:
    int totalFruit(vector<int>& tree) {
      unordered_map<int,int> count;
      int i,j,ans=INT_MIN;
      //using sliding window as a solution
      for(int i=0,j=0; j<tree.size(); ++j) { // j is one ahead of i
          count[tree[j]]++; // counting the occurences;
          while(count.size()> 2){ // checking 2 baskets
                if(--count[tree[i]]==0){ // if it was the last one.
                    count.erase(tree[i]);//delete that single element
                }
                i++; //checking for next element;
          }
          ans=max(ans, (j-i+1)); // 
      } 
      return ans;
    }
};
