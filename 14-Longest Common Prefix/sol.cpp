class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /**
        1. find minimun string and save its first char
        2. if anyones first is not matching then return empty striing  
        3. else keep iterating one it fails return the list as string
        **/
        int count =0 , min =1000;
        string str; //string having smallest length
        /**        **/
        for(int i =0; i<strs.size(); i++){
            int len=strs[i].length(); // intial length 1000
            if(len <min){ // if smaller string than current string is found 
                min=len; //update length with current lenght 
                str= strs[i]; //str will have smallest stirng in array
            }
        }
        for(int i =0 ; i<min ; i++){ // on loop untill we cover smallest string 
            for(int j=0; j<strs.size();j++){ //loop untill total Strs array size
                    if(strs[j][i] != str[i])  // j iterates over list and i iterates over each string elment 
                        return str.substr(0,count); // when they are not matching return the substring
                } 
            count++; // if one character is matched coutn++ to recoord it then if 2nd then count++ to record it.
        }
        return str.substr(0,count); // if all are matching at last return substring with count length
    }
};
