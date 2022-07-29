class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       //an iterator will chekc one by one element of arrays
    vector<int> :: iterator it ;
        it = nums.begin();
        for(int i =0; i<nums.size() ; i++){
            if(nums[i] == val){
                nums.erase(it); // erase functions does the  entire job of removing the element from the array used iterator because it takes iterator as an argument 
                it--;
                i--;
            }
            it++;
        }
     return nums.size();       
    }
};
