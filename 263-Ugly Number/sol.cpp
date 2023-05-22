class Solution {
public:
    bool isUgly(int num) {
        // while(n>1){
        //     if(n%2 ==0){
        //         n = n/2;
        //     }if(n%3 ==0){
        //         n = n/3;
        //     }if(n%5 ==0){
        //         n = n/5;
        //     }else{ 
        //         break;
        //     }
        // }
        // return n ==1;
           if (num <= 0) return false;
        if (num == 1) return true;
        if (num % 2 == 0) {
            return isUgly(num/2);
         }
        if (num % 3 == 0) {
            return isUgly(num/3);
        }
        if (num % 5 == 0) {
            return isUgly(num/5);
        }
        return false;
    }
};
