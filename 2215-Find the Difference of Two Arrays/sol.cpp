class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>> ans;
        //  // answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
        // for(int i=0; i<nums1.size(); i++){
        //    if( std::find(std::begin(nums2), std::end(nums2), nums1[i]) != std::end(nums2)){
        //         ans[0].push_back(nums1[i]);
        //    }
        // }
        // for(int i=0; i<nums2.size(); i++){
        //    if( std::find(std::begin(nums1), std::end(nums1), nums2[i]) != std::end(nums1)){
        //         ans[1].push_back(nums1[i]);
        //    }
        // }
        // answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// std::find(std::begin(arr), std::end(arr), 3) != std::end(arr)/ 
        // return ans;
        unordered_set<int> set1(nums1.begin(), nums1.end());
         unordered_set<int> set2(nums2.begin(), nums2.end());
        
         vector<int> distinct_nums1, distinct_nums2;
               for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }
        return {distinct_nums1, distinct_nums2};

    }
};
