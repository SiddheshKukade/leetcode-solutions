class Solution {
public:
    int countSegments(string s) {
        // if(s=="") return 0 ;
        // vector<string>v;
        // string word ="";
        // int i = 0 ;
        // for(char ch: s){
        //     while(i<s.size() && s[i]==' ') i++;
        //     if(ch != ' '){
        //         word+= ch;
        //     }else{
        //         v.push_back(word);
        //         word = "";
        //     }
        // }   
        // v.push_back(word);
        // return v.size();

        int k =0;
        if(s.size() ==0) return 0;
        int i=0;
        while(i<s.size()){
            while(i<s.size() && s[i]==' ') i++; /// skipping all empty spaces
            if(i== s.size()) break;
            k++; // counting that word.
            while(i<s.size() && s[i] != ' ')i++; /// skipping all the empty spaces 
        }
        return k ;
    }
};
