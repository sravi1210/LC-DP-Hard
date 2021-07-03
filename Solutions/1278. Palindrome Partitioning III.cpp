/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int palindromePartition(string S, int K) {
        int len  = S.length();
        vector<vector<vector<int>>> dp;
        
        for(int i=0;i<=K;i++){
            vector<vector<int>> arr;
            for(int j=0;j<len;j++){
                vector<int> vec;
                for(int k=0;k<len;k++){
                    vec.push_back(-1);
                }
                arr.push_back(vec);
            }
            dp.push_back(arr);
        }
        
        for(int k=1;k<=K;k++){
            for(int srt=len-1;srt>=0;srt--){
                int end = len-1;
                int count = INT_MAX;
                if(end-srt+1 == k){
                    dp[k][srt][end] = 0;
                }
                else if(end-srt+1 < k){
                    dp[k][srt][end] = -1;
                }
                else{
                    for(int par_ind = srt;par_ind<len;par_ind++){
                        if(k == 1){
                            if(S[srt] == S[par_ind]){
                                if(srt+1 <= par_ind-1){
                                    dp[k][srt][par_ind] = dp[k][srt+1][par_ind-1];
                                }
                                else{
                                    dp[k][srt][par_ind] = 0;
                                }
                            }
                            else{
                                if(srt+1 <= par_ind-1){
                                    dp[k][srt][par_ind] = 1 + dp[k][srt+1][par_ind-1];
                                }
                                else{
                                    dp[k][srt][par_ind] = 1;
                                }
                            }
                        }
                        else{
                            if(par_ind+1<=end){
                                if(dp[1][srt][par_ind] != -1 && dp[k-1][par_ind+1][end] != -1){
                                    count = min(count, dp[1][srt][par_ind]+dp[k-1][par_ind+1][end]);
                                }
                            }
                        }
                    }
                    if(k>1 && count!=INT_MAX){
                        dp[k][srt][end] = count;
                    }
                }
            }
        }
        
        return dp[K][0][len-1];
        
    }
};