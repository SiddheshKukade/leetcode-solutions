class Solution {
public:
    int minFlipsMonoIncr(string s) {
    //   // if once comes for then there can't be any more zeros furthur
    //        // Traverse the string
    //        bool flag = false;
    //        int count =0;
    // for (int i = 0; i < s.length(); i++) {
    //         if(s[i]=='1'){
    //             flag=true;
    //         }
    //         if(s[i]=='0' && flag== true){
    //             count++;
    //         }
    // }
    // return count;

    int flips=0, counter=0;
    for(auto c: s){
        if(c=='1')
            counter++;
        else
            flips++;
        flips = min(counter, flips);
    }
return flips; 
    }
};
