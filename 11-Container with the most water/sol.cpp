class Solution {
public:
    int maxArea(vector<int>& height) {
        int first=0, last=height.size()-1;
        int maxarea= 0;

        while(first < last){
           int area=  min(height[first], height[last]) * ( last -first);
           maxarea = max(area, maxarea);
           if(height[first] < height[last]) first++;
           else last--; 
        }
        return  maxarea;
    }
};a
