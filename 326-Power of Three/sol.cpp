class Solution {
public:
    bool isPowerOfThree(int n) {
        // log bas 3 of 27 is = 3 
        // log base 3 of 2 is = 2
        //we just check whether the answer is whole number of nor if it is then it is very good.
        if(n <=0 ) return false;
        double f = (double) log10(n) / log10(3); 
        return ceil(f) == floor(f); // make sure the number is not in points 
    }
};
