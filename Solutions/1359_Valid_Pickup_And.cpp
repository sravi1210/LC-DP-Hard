/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int countOrders(int n) {
        long long int dp = 1;
        long long int mod = 1000000007;
        for(int k=2;k<=n;k++){
            long long int res = 1;
            long long int fact = ((((long long int)k-1)*2) + 1);
            res *= k;
            res %= mod;
            res *= fact;
            res %= mod;
            res *= dp;
            res %= mod;
            dp = res;
            // dp[k] =k*((k-1)*2+1)*dp[k-1];
        }
        return (int)dp;
    }
};