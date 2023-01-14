class DSU{
    public:
    vector<int> rank; 
    vector<int> parent;

    DSU(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i=0; i<n;i++){
            rank[i] = i;// [0,1,2,3,4,5,..,n]
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(x == parent[x]){
        return x; // if parent is same as input
        }

        return parent[x] = findParent(parent[x]); // store it in parent
    }

void makeUnion(int x, int y){
        int p1= findParent(x) ,p2 = findParent(y);
        if(p1!=p2){ // they're not the same.
// just setting the lexicographically smallest as parent here
            if(rank[p1]<rank[p2]){ // if found 
                parent[p2] = p1; // make it parent
            }else{
                parent[p1]=p2; // else make other parent
            }
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
     DSU dsu(26);
     for(int i=0; i<s1.size(); i++){
         dsu.makeUnion(s1[i]-'a', s2[i]-'a');
     }
     string ans;
     for(int i=0 ; i<baseStr.size(); i++){
         char ch = dsu.findParent(baseStr[i]-'a') +'a';
         ans+=ch;
     }
     return ans;
    }
};
