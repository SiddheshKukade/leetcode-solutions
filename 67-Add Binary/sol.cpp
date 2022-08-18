class Solution {
public:
    string addBinary(string a, string b) {
        // we have to add with binary addition 
        // in which special condition is that 1 + 1 is 0 with a carry as 1 .
         int alen = a.length();
         int blen = b.length();
        int i =0 , carry=0;
        string ans ="";
        
        while(i<alen || i<blen || carry!=0){ // only if we are in a range and we have some left in carry
            int  x = 0; // holds ans of b reseting to 0 at every iterations
            if(i < alen && a[alen-i-1]== '1'){ // i logic is used to get the last cvalue 
                x=1;
            }
            int y=0; // holds ans of b reseting to 0 at every iterations
             if(i < blen && b[blen-i-1]== '1'){
                 y=1;
             }
            ans = to_string((x+y+carry)%2)+ans; //appending before the answer//using mod because to avoid odd numbers if occured 
            carry = (x+y+carry) /2; // adding the carry if any
            i+=1;
             
        }
        return ans;
        
    }
};
