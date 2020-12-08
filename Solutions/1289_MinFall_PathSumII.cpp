/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        
        vector<vector<int>> dp;
        for(int i=0;i<rows;i++){
            vector<int> vec;
            for(int j=0;j<cols;j++){
                vec.push_back(0);
                if(i == rows-1){
                    vec[j] = arr[i][j];
                }
            }
            dp.push_back(vec);
        }
        
        for(int i=rows-2;i>=0;i--){
            int Findex = i;
            int Sindex = i+1;
            for(int j=0;j<cols;j++){
                int count = INT_MAX;
                for(int k=0;k<cols;k++){
                    if(j!=k){
                        count = min(arr[Findex][j] + dp[Sindex][k], count);
                    }
                }
                dp[Findex][j] = count;
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<cols;j++){
            ans = min(ans, dp[0][j]);
        }
        return ans;        
    }
};