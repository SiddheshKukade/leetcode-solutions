class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum =0, prod=1;
        while(n>0){
            int temp = n % 10;
            sum += temp;
            prod *= temp;
            n = n /10;
        }
        return (prod-sum);
    }
};
