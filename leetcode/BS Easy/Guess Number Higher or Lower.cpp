//https://leetcode.com/problems/guess-number-higher-or-lower/submissions/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans=0;int lo = 1; int hi = INT_MAX;
        while(guess(ans)==1||guess(ans)==-1){
            ans = lo+(hi-lo)/2;
            if(guess(ans)==0)
                break;
            else if(guess(ans)==1){
                lo = ans+1;
            }
            else if(guess(ans)==-1)
            {
                hi = ans-1;
            }
            
        }
        return ans;
        
    }
};