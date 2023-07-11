class Solution {
public:
    vector<int> constructRectangle(int area) {
//       L >= W.  
//         smallest diff
        // int t = sqrt(area);
        // if(area % 2 ==0) {
        //     return {t,t};
        // }
        // else {return {area,1};}
        
        vector<int> answer;
        int width = 1;
        for(int i = 1; i <= sqrt(area); i++){
            if(area % i == 0) width = i;
        }
        answer.push_back(area / width);
        answer.push_back(width);
        return answer;
    }
};