441. Arranging Coins
class Solution {
public:
    int arrangeCoins(int n) {
        // TLE
        // /// n is number of coins.
        // int row =0;
        // while(n >0 ){
        //     if(row <= n ){
        //         n -= row;
        //     }else{
        //         break;
        //     }
        // }
        // return row;

        long left = 0 , right= n;
     // gives the total sum of nos untll k;
        while(left<=right){
            long mid = left + ( right- left) / 2;
            long k = mid * (mid + 1 ) /2;
            if(k == n ) 
            { return (int)mid;
            } else if(k > n ) {
                right = mid -1;
            }else {
                left = mid +1;
            }
        }
        return (int)right;
    }
};

