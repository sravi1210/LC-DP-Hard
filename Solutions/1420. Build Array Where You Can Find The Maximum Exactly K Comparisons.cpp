/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    long long int pow(long long base, long long exp){
        long long int ans = 1;
        long long int mod = 1000000007;
        for(long long int i=1;i<=exp;i++){
            ans = ans*base;
            ans%=mod;
        }
        return ans;
    }
    
    long long int func(long long int n, long long int m){
        long long int  ans = 0;
        long long int  mod = 1000000007;
        for(long long int  i=1;i<=m;i++){
            long long int  d = pow(i, n-1);
            d = d%mod;
            ans += d;
            ans = ans%mod;
        }
        return ans%mod;    
    }
    
    int numOfArrays(int N, int M, int K) {
        vector<vector<vector<long long int>>> dp;
        for(int i=0;i<=N;i++){
            vector<vector<long long int>> arr;
            for(int j=0;j<=M;j++){
                vector<long long int> vec;
                for(int k=0;k<=K;k++){
                    vec.push_back(0);
                }
                arr.push_back(vec);
            }
            dp.push_back(arr);
        }
        long long int mod = 1000000007;
        
        for(int n=1;n<=N;n++){
            for(int m=1;m<=M;m++){
                for(int k=1;k<=K;k++){
                    if(k>n || k>m){
                        dp[n][m][k] = 0;
                        continue;
                    }
                    if(k == 1){
                        if(n == 1){
                            dp[n][m][k] = m;
                        }
                        else{
                            dp[n][m][k] = func((long long int)n, (long long int)m);
                        }
                    }
                    else{
                        long long int count = 0;
                        count += dp[n-1][m-1][k-1];
                        count += dp[n][m-1][k];
                        
                        long long int diff = 0;
                        diff+= dp[n-1][m][k] - dp[n-1][m-1][k];
                        
                        
                        diff = diff*m;
                        count = count+diff;
                        
                        count%=mod;
                        if(count<0){
                            count = count+mod;
                        }
                        
                        dp[n][m][k] = count;
                        
                        // dp[n][m][k] = dp[n-1][m-1][k-1] + dp[n][m-1][k]+ m*dp[n-1][m][k] - m*dp[n-1][m-1][k];
                    }
                }
            }
        }

        return (int)dp[N][M][K];
        
    }
};