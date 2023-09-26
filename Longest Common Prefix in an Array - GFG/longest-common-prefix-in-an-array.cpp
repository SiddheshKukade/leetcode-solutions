//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    int childcount;
    bool ismatch;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        ismatch=false ;
        childcount=0;
    }
    
};
class Trie{
    public:
        TrieNode*root;
        Trie(char ch){
            root=new TrieNode(ch);
        }
        void insert(TrieNode*root,string keys){
            if(keys.length()==0){
                root->ismatch=true;
                return;
            }
            int index=keys[0]-'a';
            TrieNode*child;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }else{
                child=new TrieNode(keys[0]);
                root->childcount++;
                root->children[index]=child;
            }
            insert(child,keys.substr(1));
        }
        void insertstring(string keys){
            insert(root,keys);
        }
        void lcp(string data,string &ans){
            for(int i=0;i<data.length();i++){
                char ch=data[i];
                if(root->childcount==1){
                    ans.push_back(ch);
                    int index=ch-'a';
                    root=root->children[index];
                }else{
                    break;
                }
                if(root->ismatch){
                    break;
                }
            }
            
        }
};
class Solution{
  public:
    
    string longestCommonPrefix (string strs[], int N)
    {
        // // your code here
        // Trie *t = new Trie('\0');
        //   for(int i=0;i<N;i++){
        //     t->insertstring(arr[i]);
        // } 
        // string data=arr[0];
        // string ans="";
        // t->lcp(data,ans);
        //   if(ans.length()==0){
        //     return "-1";
        // }
        // return ans;
         int count =0 , min =1000;
        string str; //string having smallest length
        /**        **/
        for(int i =0; i<N; i++){
            int len=strs[i].length(); // intial length 1000
            if(len <min){ // if smaller string than current string is found 
                min=len; //update length with current lenght 
                str= strs[i]; //str will have smallest stirng in array
            }
        }
        for(int i =0 ; i<min ; i++){ // on loop untill we cover smallest string 
            for(int j=0; j<N;j++){ //loop untill total Strs array size
                    if(strs[j][i] != str[i]){
                          if(count ==0) return "-1";
                        return str.substr(0,count); // when they are not matching return the substring
                    }  // j iterates over list and i iterates over each string elment 
                } 
            count++; // if one character is matched coutn++ to recoord it then if 2nd then count++ to record it.
        }
        // cout<<count<<"---";
      
        return str.substr(0,count); 
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends