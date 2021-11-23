//https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo =1; int hi =n;
        int ans = 1;
        
        while(hi >= lo){
            int mid = lo + (hi-lo)/2;
            
            if(isBadVersion(mid)){
                ans  = mid;
                hi = mid-1;
            }
            
            else{
    lo = mid+1;
            }
        }
        return ans;
        
    }
};

