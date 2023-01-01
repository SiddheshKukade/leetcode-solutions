class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // edge case
        // same numbers of words for the input string
        vector<string> v ;
        int i=0;
        string temp =""; 
        // storing the words in the v vector
        while(i < s.size()){
            if(s[i] == ' '){
                v.push_back(temp);
                temp="";
            }else{
                temp +=s[i];
            }
            i++;
        }
        v.push_back(temp);

    if(v.size() !=  pattern.size()){
        return false;
    }
    unordered_map<char, string> m;
    set<string> st;

    for(int i=0 ; i<pattern.size() ; i++){

        if(m.find(pattern[i]) != m.end()){ // if pattern is found in the string
            if(m[pattern[i]] != v[i]){ // if differernt pattern already exists
                return false;
            }
        }
        
        else{ // not in hashmap
            if(st.count(v[i]) > 0){ // checks that current vector word in not assigned to any integer.
                return false;
            }
            m[pattern[i]] = v[i] ; // add new combo to map;
            st.insert(v[i]); // also add to set to check for duplicates
        }
    }
    return true; 
    }
};
