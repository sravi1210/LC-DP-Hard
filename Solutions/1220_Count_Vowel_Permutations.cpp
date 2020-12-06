/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1){
            return 5;
        }
        vector<vector<long long int>> dp;
        for(int i=0;i<=n;i++){
            vector<long long int> vec;
            for(int j=0;j<5;j++){
                vec.push_back(0);
            }
            dp.push_back(vec);
        }
        dp[2][0] = 1; //2 digit starting with 'a' - 0
        dp[2][1] = 2;
        dp[2][2] = 4;
        dp[2][3] = 2;
        dp[2][4] = 1;
        
        long long int mod = 1000000007;
        
        
        for(int i=3;i<=n;i++){
            for(int j=0;j<5;j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][1]; //a-e__
                    dp[i][j] %= mod;
                }
                else if(j == 1){
                    dp[i][j] = dp[i-1][0] + dp[i-1][2];
                    dp[i][j] %= mod;
                }
                else if(j == 2){
                    dp[i][j] = dp[i-1][0] + dp[i-1][1];
                    dp[i][j] %= mod;
                    dp[i][j] += dp[i-1][3];
                    dp[i][j] %= mod;
                    dp[i][j] += dp[i-1][4];
                    dp[i][j] %= mod;
                }
                else if(j == 3){
                    dp[i][j]  = dp[i-1][2] + dp[i-1][4];
                    dp[i][j] %= mod;
                }
                else{
                    dp[i][j] = dp[i-1][0];
                    dp[i][j] %= mod;
                }           
            }
        }

        long long int ans = 0;
        for(int i=0;i<5;i++){
            ans += dp[n][i];
            ans%=mod;
        }
        return (int)ans;
    }
};