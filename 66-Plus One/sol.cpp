class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // if(digits[digits.size() - 1 ]  == 9 ) {
        //     digits[digits.size() - 1 ] = 1;
        //     digits.push_back(0);
        //     return digits;
        // }
        // digits[digits.size() - 1 ] = digits[digits.size() - 1 ] + 1 ;
        // return digits;
        
        int n= digits.size();
        for(int i =n -1 ;i>=0; i-- ){
            if(digits[i] !=9){
                digits[i]++;
                break; // exit out of loop
            }else{
                digits[i]=0;
            }
        }
        if(digits[0] == 0 ){//9999
            digits.push_back(0);
            digits[0] = 1 ;
            return digits; 
        }
        return digits;
        
    }
};
