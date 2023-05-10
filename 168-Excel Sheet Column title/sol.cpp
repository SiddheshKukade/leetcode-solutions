class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans ="";
        while(columnNumber){
            char c =( columnNumber-1) % 26 + 'A';
            ans= c+ans;  // will not work if += is used
            columnNumber = (columnNumber-1) /26;
        }
        return ans;
    }
};
