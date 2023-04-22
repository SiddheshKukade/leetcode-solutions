class Solution {
public:
    string toLowerCase(string s) {
  //use ASCII  
    int i=0;
      for(char x :s){
          if(x>=65 && x<=90){
              x+=32;
              s[i]=x;
          }
          i++;
          
      }
      return s;
    }
};
