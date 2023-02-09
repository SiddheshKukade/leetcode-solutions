class Solution {
public:
// // algorithm
    // a[i] < a[i+1]  ind=1
    // a[ind2] > a[ind1] ind2 =3
//swap(a[ind1] , a[ind2])
// reverse(ind+1 -> last)
    void nextPermutation(vector<int>& nums) {
        //  Tc o 3n
        // SC o 1
        // 1 5,3,2,6 = 2
        //        
        int n = nums.size(), k,l;
        for(k = n-2; k>=0;k--){ // from second last reverse iterate to start
            if(nums[k]<nums[k+1]){ // if current  is smaller than it's next
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(), nums.end()); // if not break point then just reverse entire  thing
        }else{ // if there is brekpoint again traverse from the back
            for(l= n-1; l>k;l--){ // from last untill k
                if(nums[l]> nums[k]){ //find the no from the last that it greater than k
                    break; 
                }
            }
            swap(nums[k], nums[l]); // then  swap that element with k
            reverse(nums.begin()+k+1, nums.end());
        }
    }
};
