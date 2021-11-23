// https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int n;
    
    bool check(vector<int>& arr, int mid){
        return arr[mid]>arr[mid-1]; 
    }
    int peakIndexInMountainArray(vector<int>& arr) {
    n= arr.size();
        int lo =1; int hi =n-1;
        int ans=1; 
        while(hi>=lo){
            int mid = lo+ (hi-lo)/2;
            if(check(arr,mid)){
                ans = mid;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return ans;
    }
};