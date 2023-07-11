class Solution {
public:
    bool checkRecord(string s) { 
        int n = s.size();
        int as=0;
        int ls=0;
        for(char ch: s){
                if(ch == 'A') {
                    as++; ls=0;
                              
                             }
                else if(ch == 'L'){
                    ls++;
                    if(ls==3){
                        return false;
                    }
                 }else{
                    ls=0;
                }
            }
     if(as <2) { return true;}
    return false;
    }
};