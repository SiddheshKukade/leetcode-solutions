class Solution {
public:
    int mySqrt(int x) {
        // finding the square root of a number
        // for(int i=0; i<=x; i++){
        //     int temp  = i * i ; 
        //     if(temp>x){
        //         return i-1;
        //     }
        // }
        // return 0;
        long long y=0;
        while(y*y<=x) y++;
        return y-1;
    }
};
