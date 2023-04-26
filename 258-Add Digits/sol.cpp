class Solution {
public:
    int addDigits(int num) {
        // use mod by 10 to get unit 
        //delete unit by using divide
        int sum=0;
        while(num>9 ){
            while(num){
                sum+= num%10 ;
                num = num/10;
            }
            num = sum;
            sum=0;
        }   
        return num;     
    }
};
