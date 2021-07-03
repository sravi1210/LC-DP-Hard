/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp;
        for(int i=0;i<rows;i++){
            vector<vector<int>> arr;
            for(int j=0;j<cols;j++){
                vector<int> vec;
                for(int k=0;k<cols;k++){
                    vec.push_back(-1);
                    if(i==rows-1){
                        if(j!=k){
                            vec[k] = grid[i][k] + grid[i][j];
                        }
                        else{
                            vec[k] = grid[i][j];
                        }
                    }
                }
                arr.push_back(vec);
            }
            dp.push_back(arr);
        }
        
        for(int i=rows-2;i>=0;i--){
            for(int j=0;j<cols;j++){
                for(int k=0;k<cols;k++){
                    int count = INT_MIN;
                    for(int indexj=-1;indexj<=1;indexj++){
                        for(int indexk=-1;indexk<=1;indexk++){
                            int nj = j + indexj;
                            int nk = k + indexk;
                            if(nj>=0 && nj<cols && nk>=0 && nk<cols){
                                count = max(dp[i+1][nj][nk], count);
                            }
                        }
                    }
                    if(j!=k){
                        count+= grid[i][j] + grid[i][k];
                    }
                    else{
                        count+= grid[i][j];
                    }
                    dp[i][j][k] = count;
                }
            }
        }
        
        return dp[0][0][cols-1];        
    }
};