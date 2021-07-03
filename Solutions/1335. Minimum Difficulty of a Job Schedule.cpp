/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int size = jobDifficulty.size();
        if(d>size){
            return -1;
        }
        vector<vector<int>> dp;
        for(int i=0;i<=d;i++){
            vector<int> vec;
            for(int j=0;j<size;j++){
                vec.push_back(-1);
                if(i==1){
                    vec[j] = jobDifficulty[j];
                }
            }
            dp.push_back(vec);
        }
        
        for(int i=1;i<=d;i++){
            for(int j=size-1;j>=0;j--){
                if(i>size-j){
                    dp[i][j] = -1;
                }
                else if(i == 1){
                    if(j < size-1){
                        dp[i][j] = max(dp[i][j], dp[i][j+1]);
                    }
                }
                else{
                    int res = INT_MAX;
                    int maxy = 0;
                    for(int par_ind=j;par_ind+1<size;par_ind++){
                        maxy = max(maxy, jobDifficulty[par_ind]);
                        if(dp[i-1][par_ind+1] != -1){
                            res = min(res, maxy+dp[i-1][par_ind+1]);
                        }
                    }
                    if(res!=INT_MAX){
                       dp[i][j] = res;
                    } 
                }
                
            }
        }
        return dp[d][0]; 
    }
};