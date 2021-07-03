/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    /*
        The idea here is similar to as of merging intervals just here we do go by size from 1 to N, and
        for every size we take left and right of every damn interval and there between them we find that
        one k at which the nums[k]*nums[left-1]*nums[right+1] + dp[left][k-1] + dp[k+1][right] is maximum.
    */
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp;
        for(int i=0;i<=len+2;i++){
            vector<int> vec;
            for(int j=0;j<=len+2;j++){
                vec.push_back(0);
            }
            dp.push_back(vec);
        }
        
        for(int size=1;size<=len;size++){
            for(int left=1;left<=len-size+1;left++){
                int right = left+size-1;
                for(int k=left;k<=right;k++){
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
                }
            }
        }
        
        return dp[1][len];
    }
};