class Solution {
public:
    char findTheDifference(string s, string t) {
        // USING HASHMAP TO KEEP TRACK OF CHARACTERS.
        // SC length of String
        // TC O(N)

        // SOLUTUION WITHOUT EXTRA SPACE
    // convert chars to ASCII values

    // SUBTRACT one string with other
    // remaining value is the ascii of the answer.
    int a=0;
    int b=0;
    for(char c: s){
        a+= c;
    }
    for(char c:t){
        b +=c;
    }
    return b-a;
    }
};
