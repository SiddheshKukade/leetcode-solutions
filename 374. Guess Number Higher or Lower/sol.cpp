CPP Binary search
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s=1, end =n;
        // binary search

        while(s<=end){
            long long  mid = s+ (end-s)/2;
            int res = guess(mid);
            if(res == 0){ return mid;}
            else if (res == -1){ end = mid-1;}
            else{ s = mid+1;}
        }
        return 0 ;


        // for(int i=1; i<=n; i++){
        //     int res = guess(s);
        //     int res2 = guess(end);
        //     if(res || res2){
        //         return 
        //     }
        //    s++;
        //    e--;
        // }
    }
};
