## ASKED IN GOLDMAN SACHS

class Solution {
public:
    vector<int> getRow(int rowIndex) {
     /// all are the powers of 11
     vector<int> result(rowIndex+1,1); // initialized with 1s
     for(int i=1; i<rowIndex; i++){
         for(int j=i; j>0;--j){
                result[j] += result[j-1];
         }
     }
         return result;
    }
};
