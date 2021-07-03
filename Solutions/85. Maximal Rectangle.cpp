/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0){
            return 0;
        }
        int cols = matrix[0].size();
        
        vector<vector<int>> dp;
        for(int i=0;i<rows;i++){
            vector<int> vec;
            for(int j=0;j<cols;j++){
                int count = 1;
                if(matrix[i][j] == '0'){
                    count = 0;
                }
                vec.push_back(count);
            }
            dp.push_back(vec);
        }
        
        
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(i == rows-1 && j == cols-1){
                    continue;
                }
                else if(i == rows-1){
                    dp[i][j] += dp[i][j+1];
                }
                else if(j == cols-1){
                    dp[i][j] += dp[i+1][j];
                }
                else{
                    dp[i][j] += dp[i][j+1] + dp[i+1][j] - dp[i+1][j+1];
                }
            }
        }
        
        int area = 0;
        for(int i=0;i<rows;i++){
            for(int j=i;j<rows;j++){
                int height = j-i+1;
                int left = -1;
                for(int k=0;k<cols;k++){
                    int ones = 0;
                    if(j+1<rows){
                        ones += dp[i][k] - dp[j+1][k];
                    }
                    else{
                        ones += dp[i][k];
                    }
                    if(k+1<cols && j+1<rows){
                        ones -= dp[i][k+1]-dp[j+1][k+1];
                    }
                    else if(k+1<cols){
                        ones -= dp[i][k+1];
                    }
                    if(ones == height){
                        if(left == -1){
                            left = k;
                        }
                        area = max(area, height*(k-left+1));
                    }
                    else{
                        left = -1;
                    }
                }
            }
        }
        return area;
    }
};