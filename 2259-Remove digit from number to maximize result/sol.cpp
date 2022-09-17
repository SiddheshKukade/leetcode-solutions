class Solution {
public:
    string removeDigit(string number, char digit) {
        // to choose the number to delete we will check if the next postition number is biggest
        int i=1;
        for(;i<number.length();i++){
            if(number.at(i-1) == digit){
                if(number.at(i)>number.at(i-1)){
                    return (number.substr(0,i-1)+number.substr(i)); // skipping that character
                }
            }
        }
        int lastIndex = number.find_last_of(digit); // last instance of the target
        return (number.substr(0,lastIndex) + number.substr(lastIndex+1));
        //returning a string by skipping that character
        //choosing the last one because it would never be greater than the first ones for the answer
    }
};
