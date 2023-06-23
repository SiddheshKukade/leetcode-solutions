class NumArray {
public:
    vector<int> n ;
    NumArray(vector<int>& nums) {
        n = nums;
    }
    
    int sumRange(int left, int right) {
        int sum =0;
        for(int i=left; i<=right; i++){
            sum+=n[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
