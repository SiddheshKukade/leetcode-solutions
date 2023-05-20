class Solution {
public:
    bool isPowerOfTwo(int n) {
           if(!n) return false;
           if(n==1) return true;
           return n%2==0 and isPowerOfTwo(n/2);
    }
    //1 ,2, 4, 8,16,32,64...
};
