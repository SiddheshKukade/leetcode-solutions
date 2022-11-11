class Solution {
public:
    string getPermutation(int n, int k) {
        int fact =1 ;
        vector<int> numbers; // containns factorials of n numbers
        for(int i=1; i<n ; i++){
            fact = fact * i ;
            numbers.push_back(i);
        }
        numbers.push_back(n); // add no in array 
        string ans = "";
        k = k -1 ; /// we are on zero based indezing 
        
        while(true){
            ans = ans + to_string(numbers[ k / fact]); // enter the elemet by its group 
            numbers.erase(numbers.begin() + k / fact ); // delete thos elements
            if(numbers.size() ==0 ){ // if factorial array in finished
                break;
            }
            k = k % fact; // reduce the current index to find next index group
            fact = fact / numbers.size(); // next facotirial is 1 factorial less
        }
        return ans;
    }
};
