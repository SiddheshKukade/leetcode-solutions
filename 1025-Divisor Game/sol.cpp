class Solution {
public:
    bool divisorGame(int n) {
        //Microsft , payTM
        //alice makes the first move.
        if(n<=1) return false; //base case means bob loses
        for(int i=1;i<n;i++){
            if(n%i==0) {
                return !divisorGame(n-i); //inverting means alice means
            }
        }
        return false;
    }
};
