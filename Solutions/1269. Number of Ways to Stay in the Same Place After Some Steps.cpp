/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int numWays(int steps, int arrLen) {
        if(steps == 0 || steps == 1){
            return steps;
        }
        
        vector<vector<long long int>> dp;
        int min_index = min(steps/2, arrLen-1);
        long long int mod = 1000000007;
        
        for(int i=0;i<=min_index;i++){
            vector<long long int> vec;
            for(int j=0;j<=steps;j++){
                vec.push_back(0);
            }
            dp.push_back(vec);
        }
        
        for(int step=0;step<=steps;step++){
            for(int index=0;index<=min_index;index++){
                if(steps < index){
                    dp[step][index] = 0;
                }
                else if(step == 0){
                    dp[index][step] = 1;
                }
                else if(step == 1){
                    if(index == 0 || index == 1){
                        dp[index][step] = 1;
                    }
                }
                else{
                    long long int count = 0;
                    if(index+1<=min_index){
                        count = count + dp[index+1][step-1];
                    }
                    if(index-1>=0){
                        count = count + dp[index-1][step-1];
                    }
                    count = count + dp[index][step-1];
                    count %= mod;
                    dp[index][step] = count;
                }
            }
        }
        
        return (int)dp[0][steps];
    }
};