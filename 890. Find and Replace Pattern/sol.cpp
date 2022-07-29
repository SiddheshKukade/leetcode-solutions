## Not working
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)     {
//  create a hasmap that stores the pattern and the copmpare string character by character with hashmap
// create another HasMap to reverify it
        vector<string> ans ;
           int flag = 1; 
        for(int i =0 ; i<words.size() ; i++){
            // words list 
            map<char, char> m1; 
            map<char, char> m2; 
            
            for(int j =0 ; j<words[i].size(); j++){
               auto  it = m1.find(pattern[j]); // find 'a'
               auto  it2 = m2.find(words[i][j]); // find 'm'
                //words[i] = "mee" pattern="abb"
                if(it==m1.end()){
                    //not found then insert the pattern
                    m1.insert({pattern[j], words[i][j]}); // a:m
                }
                else{
                    if(it->second != words[i][j] ) // a:r ? 
                    { 
                        flag=0; //reporting the problem 
                        break;
                    }
                }
                 if(it2==m2.end()){
                 
                    m2.insert({ words[i][j],pattern[j]});  
                }
                else{
                    if(it2->second != pattern[j] ) // a:r ? 
                    { 
                        flag=0; //reporting the problem 
                        break;
                    }
                }
                
            }
             if(flag){ ans.push_back(words[i]);}
        }
        
    
        return ans;
    }
};
