415. Add Strings
class Solution {
public:
    string addStrings(string x, string y) {
        if(x[0] == '0' && y[0]=='0')
                return "0";
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int a  = x.size();
        int b = y.size();
        int c = abs(a-b); /// diff between decimals
        if(a>b){
            while(c--){
                y.push_back('0');
            }
        }else if(a<b){
            while(c--){
                x.push_back('0');
            }
        }

        int carry=0;
        string ans = "";
        for(int i=0; i<x.size(); i++){
            int d = x[i] - 48;
            int e = y[i] - 48;
            int sum = d+e+carry;
            if(sum<10){
                ans.push_back(sum+'0');
                carry=0;
            }else{
                int f = sum%10;
                ans.push_back(f+'0');
                carry = 1;
            }
        }
        if(carry==1){
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
