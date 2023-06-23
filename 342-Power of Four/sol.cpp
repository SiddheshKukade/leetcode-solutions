class Solution {
public:
    bool isPowerOfFour(int num) {
      // if we keep right shifting then the base case is 1 
      // so if we made even number of right ifts then the number is in the power of four. else it is not.

// log4(n)

    if(num < 1) return false;
    int n = num , count=0;
    while(n>1){
        n>>=2;
        count+=2;
    }
    return (n<<count) == num ; // if more than one bit is set then ans is false;


      // if(n<=0) return false;
      // if(n%4 ==0  || n ==1 ){
      //    return true;
      // } 
      // return false;

    }
};
