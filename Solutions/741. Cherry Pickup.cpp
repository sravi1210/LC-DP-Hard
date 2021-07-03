/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int maxCherry(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r1, int c1, int r2, int size){
        int c2 = r1+c1-r2;
        
        if(r1>=size || r2>=size || c1>=size || c2>=size || c2<0 || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2] != INT_MIN){
            return dp[r1][c1][r2];
        }
        
        int ans = grid[r1][c1];
        if(r1 == size-1 && c1 == size-1){
            return ans;
        }
        if(r1!=r2){
            ans += grid[r2][c2];
        }
        
        int temp = max(maxCherry(grid, dp, r1, c1+1, r2, size), max(maxCherry(grid, dp, r1+1, c1, r2+1, size), max(maxCherry(grid, dp, r1+1, c1, r2, size), maxCherry(grid, dp, r1, c1+1, r2+1, size))));
        
        ans += temp;
        dp[r1][c1][r2] = ans;
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<vector<vector<int>>> dp;
        
        for(int i=0;i<size;i++){
            vector<vector<int>> arr;
            for(int j=0;j<size;j++){
                vector<int> vec;
                for(int i=0;i<size;i++){
                    vec.push_back(INT_MIN);
                }
                arr.push_back(vec);
            }
            dp.push_back(arr);
        }
        
        int ans = maxCherry(grid, dp, 0, 0, 0, size);
        return max(0, ans);
    }
};