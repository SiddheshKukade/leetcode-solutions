class Solution {
public:
    static bool compute(vector<int> &a, vector<int>&b){
        if(a[0]==b[0] ) return a[1]>b[1]; // if thier first is same then check defence
        return a[0]< b[0]; // else compare attack
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //firstly we will sort the 2d Array
        // so biggest attack will be on the last the we'll 
        //check if it's defense is stronger than others or not 
        // and will keep counting the smaller elements
        int n= properties.size();
        sort(properties.begin(), properties.end(),compute );
        
        int maxdef = INT_MIN;
        int count = 0;
        for(int i=n-1 ; i>=0 ; i--){
            //check if current element defense is greater than maxdef
            if(properties[i][1]< maxdef) count ++; 
            //keep value updated to maximun defense
            maxdef = max(maxdef , properties[i][1]);
            //update maxdef everytime with previous elemnt to compare the next one 
        }
        return count;
    }
};
