/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

//https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/471601/Clean-DP-solution-with-explanation
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int N = stones.size();
        if((N-1)%(K-1) != 0){
            return -1;
        }
        
        vector<vector<int>> dp;
        for(int i=0;i<=N;i++){
            vector<int> vec;
            for(int j=0;j<=N;j++){
                vec.push_back(0);
            }
            dp.push_back(vec);
        }
        
        vector<int> sum;
        sum.push_back(0);
        for(int i=1;i<=N;i++){
            sum.push_back(sum[i-1]+stones[i-1]);
        }
        
        for(int L=K;L<=N;L++){
            for(int i=0,j=i+L-1; j<N ;i++,j++){
                
                dp[i][j] = INT_MAX;
                for(int k=i;k<j;k+=(K-1)){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
                
                if((L-1)%(K-1) == 0){
                    dp[i][j] += sum[j+1] - sum[i];
                }
                
            }
        }
        
        return dp[0][N-1];
    }
};