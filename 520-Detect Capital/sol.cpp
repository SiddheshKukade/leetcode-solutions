class Solution {
    bool isLower(char c ){
        return c>= 'a' and c<= 'z';
    }
    bool isUpper(char c ){
        return c>= 'A' and c<= 'Z';
    }
public:

    bool detectCapitalUse(string word) {
    int n = word.size();
    int Upper = 0; // uppercase counter

    for(int i=0 ; i<n;i++){
        if(word[i] >='A' && word[i]<='Z'){
            ++Upper;
        }
    }
        if(Upper==n or Upper==0 or (word[0]>='A' and word[0] <='Z' and Upper==1))
            return true;
    

    return false;

    // Approach 1 
    //     int n = word.size();
    //     int i;
    //     // if 1st char is lowercase
    //     if(isLower(word[0])){
    //         i =1 ;
    //         while(word[i] && isLower(word[i]) )
    //         ++i;
    //         return i==n ? true: false;
    //     }
    //     // else if 2nd char is uppoercase
    //     else{
    //         // check if all are uppercase
    //         i=1;
    //         while(word[i] && isUpper(word[i]))
    //         ++i;
    //         if(i ==n)
    //         return true;
    //         else if (i >1)  
    //         return false;

    //         // if all from second are lowercase
    //         while(word[i] && isLower(word[i]))
    //         ++i;
    //         return i==n ? true : false;
    //     }

// 2 nd Approach
        // if(isupper(word[0])){
        //     if(isupper(word[1])){
        //         for(int i=2;i<word.length();i++){
        //             if(islower(word[i])){
        //                 return false;
        //             }
        //         }
                
        //     }else{
        //         for(int i=1;i<word.length();i++){
        //             if(isupper(word[i])){
        //                 return false;
        //             }
        //         }
        //     }
            
        // }else{
        //     for(int i=0;i<word.length();i++){
        //         if(isupper(word[i])){
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
};
