2749. Minimum Operations to Make the Integer Zero
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 < num2){
            return -1;
        }
        for(int k =0; k<=32; k++){
            long long diff = num1 - (long long )(num2)*k;
            int bits = __builtin_popcountll(diff);
            if(bits<=k && k<=diff){
                return k;
            }
        }
            return -1;
    }
};
