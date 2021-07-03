/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n);
        int size = dependencies.size();
        for(int i=0;i<size;i++){
            int x = dependencies[i][0]-1;
            int y = dependencies[i][1]-1;
            pre[y] |= (1<<x);
        }
        size = 1<<n;
        vector<int> dp(size, n);
        dp[0] = 0;
        
        for(int i=0;i<size;i++){
            int ex = 0;
            for(int j=0;j<n;j++){
                if((i & pre[j]) == pre[j]){
                    ex |= (1<<j);
                }
            }
            
            ex &= (~i);
            
            for(int s=ex;s;s=(s-1)&ex){
                if(__builtin_popcount(s) <= k){
                    dp[i|s] = min(dp[i|s], dp[i]+1);
                }
            }
        }
        return dp.back();
    }
};