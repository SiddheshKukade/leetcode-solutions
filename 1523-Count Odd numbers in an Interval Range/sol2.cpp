class Solution {
public:
    int countOdds(int low, int high) {
        if(low %2 ==0 && high%2 ==0){
            return (high-low)/2;
        }
        return( high-low)/2+1;
        // int oddNo = 0;
        // for(int i=low; i<=high;i++){
        //     if(i % 2 !=0){
        //         oddNo++;
        //     }
        // }
        // return oddNo;
    }
};
