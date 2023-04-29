class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      vector<int> nums1M, nums2N;
      
      for(int i=0; i<m; i++){
        nums1M.push_back(nums1[i]);
      }
      for(int i=0; i<n; i++){
        nums2N.push_back(nums2[i]);
      }
      nums1M.insert(nums1M.end() ,nums2N.begin(), nums2N.end() );
      sort(nums1M.begin(), nums1M.end());
          for (int i: nums1M){
    std::cout << i << '-';
      nums1 =nums1M;
      }
    }

};
