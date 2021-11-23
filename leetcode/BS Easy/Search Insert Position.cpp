//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int hi = arr.size()-1;
        int lo = 0;int ans  = arr.size();
        while(hi>= lo){
            int mid = lo +(hi-lo)/2;
            if(arr[mid] >= x){
                ans =mid;
                hi= mid-1;
            }
            else{
                lo = mid+1;
            }
           
            
        }
        return ans;
        
        
        
    }
};