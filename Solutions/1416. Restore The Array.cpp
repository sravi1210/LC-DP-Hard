/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int numberOfArrays(string s, int kk) {
        int len = s.length();
        vector<long long int> dp;
        for(int i=0;i<len;i++){
            dp.push_back(-1);
        }
        long long int k = (long long int)kk;
        long long int mod = 1000000007;
        
        for(int i=len-1;i>=0;i--){
            long long int count = 0;
            long long int num = 0;
            for(int j=i;j<len;j++){
                num = num*10 + (s[j]-'0');
                if(num == 0 || num > k){
                    goto here;
                }
                else if(j==len-1){
                    if(num>=1 && num<=k){
                        count += 1;
                        count %= mod;
                    }
                }
                else{
                    if(num>=1 && num<=k){
                        if(dp[j+1] != 0){
                            count += dp[j+1];
                            count %= mod;
                        }
                    }
                }
            }
            here:
            dp[i] = count;
        }
            
        return (int)dp[0];
    }
};