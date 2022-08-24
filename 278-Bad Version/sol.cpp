// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        for(int i =n ;i>=0; i--){
            if(!isBadVersion(i)){
                return i+1;
            } } 
    return 1;
    // if( n==1) return 1;
    // return isBadVersion(n) ? n-1 : firstBadVersion(--n);
    }
};
