class Solution {
public:
    bool checkPerfectNumber(int num) {
             int sum=0;
        int i=1;
        int n = num;
        while(i<n){
            if(num%i==0){//dividing evenly
                sum+=i+(num/i); /// adding divisors 
                n=num/i;
            }
            i++;
        }
        
        if(num==sum-num){ // A perfect number is a positive integer that is equal to the sum of its positive divisors,
            return true;
        }
        return false; 
    }
};