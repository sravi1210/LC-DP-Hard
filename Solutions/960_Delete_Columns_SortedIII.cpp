/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int size = A.size();
        int len = A[0].length();
        
        vector<int> dp;
        for(int i=0;i<len;i++){
            dp.push_back(1);
        }
        
        int maxlength = 1;
        for(int i=0;i<len;i++){
            int count = 0;
            for(int j=i-1;j>=0;j--){
                if(dp[j]+1 > dp[i]){
                    int k = 0;
                    for(k=0;k<size;k++){
                        if(A[k][j] > A[k][i]){
                            goto here;
                        }
                    }
                    here:
                    if(k == size){
                        dp[i] = max(dp[i], dp[j]+1);
                        maxlength = max(maxlength, dp[i]);
                    }
                }
            }
        }
        
        return len-maxlength;
    }
};