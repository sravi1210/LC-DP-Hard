/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minTaps(int n, vector<int>& nums) {
        vector<int> maxRight(n+1); //maxRight[Left]=the farest index Left can reach
        
        // scan each tap, update the farest index each Left can reach.
        for (int i =0;i<=n;i++){
            int L = max(0,i-nums[i]);
            int R = min(n,i+nums[i]);
            maxRight[L] = max(maxRight[L],R);
        }   

        int next_right_most = maxRight[0];// the rightmost index which is accessible by one more tap
        int cur_right_most = maxRight[0];// cur right most accessible index
        int taps = 1;

        for(int i=1;i<=n;i++){
            // i is the Left to scan.
            // for each i, we find the next right most index to cover.
            if(i>next_right_most){
               //still can't find the next connected range
               //this implies all indices in[0,next_right_most] cannot reach the rest part of the garden.
               //because if they can, the next_right_most should have been updated to larger.(contradicted)
               return -1;
            }
            if (i>cur_right_most){
                //this implies Left of current scan is disconnected from previous right_most index.
                //It's time to add an additional tap to cover previous indices
                taps++;
                cur_right_most = next_right_most;
            }
            
            //only update when i(which is the Left)<cur_right_most
            //because only in this case, the tap is overlapped with the previous tap
            next_right_most = max(next_right_most,maxRight[i]); //greedy. find the rightmost index
        }
        return taps; 
    }
};