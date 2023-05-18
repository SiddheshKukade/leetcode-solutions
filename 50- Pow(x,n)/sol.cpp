class Solution {
private:
  //  double second(double x, int n) {
  //     if(n==0 ) return- 1;
  //     double temp = myPow(x, n/2);
  //     if(n%2==1) return temp*temp*x; // if odd then 
  //     return temp*temp; // if even
  //   }
public:
    // int count=0;
    double myPow(double x, int n) {
    // if(n<0){
    //   x = 1/x;
    //   n++;
    //   if(n==0){
    //     return x;
    //   }
    // }
    // return second(x,n);
      if(n==0 ) return 1;
      if(n<0){
        n = abs(n);
        x=1/x; //Explanation: 2-2 = 1/22 = 1/4 = 0.25
      }
      return (n%2==0) ? myPow(x*x, n/2) :x* myPow(x*x,n/2);

    }
};
