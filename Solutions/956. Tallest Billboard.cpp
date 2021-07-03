/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    void solve(vector<int>& rods, vector<vector<int>>& dp, int index, int left, int right, int size){
        if(index>=size){
            return;
        }
        int diff = left-right+5000;
        if(dp[index][diff] != -1){
            return;
        }
        else if(index == size-1){
            if(diff == 5000){
                dp[index][diff] = 0;
            }
            else if(diff+rods[index] == 5000){
                dp[index][diff] = rods[index];
            }
            else if(diff-rods[index] == 5000){
                dp[index][diff] = 0;
            }
            else{
                dp[index][diff] = -2;
            }
        }
        else{
            //add to left
            if(dp[index+1][diff+rods[index]] == -1){
                solve(rods, dp, index+1, left+rods[index], right, size);
            }
            //add to right
            if(dp[index+1][diff-rods[index]] == -1){
                solve(rods, dp, index+1, left, right+rods[index], size);
            }
            //add to no-one
            if(dp[index+1][diff] == -1){
                solve(rods, dp, index+1, left, right, size);
            }
            int maxy = -2;
            if(dp[index+1][diff] != -2){
                maxy = max(maxy, dp[index+1][diff]);
            }
            if(dp[index+1][diff+rods[index]] != -2){
                maxy = max(maxy, rods[index]+dp[index+1][diff+rods[index]]);
            }
            if(dp[index+1][diff-rods[index]] != -2){
                maxy = max(maxy, dp[index+1][diff-rods[index]]);
            }
            dp[index][diff] = maxy;
        }
        return;
    }
    int tallestBillboard(vector<int>& rods) {
        int size = rods.size();
        vector<vector<int>> dp; // this dp will be 10001 x 21 because of difference between left and right can be negative or positive
        
        for(int i=0;i<=21;i++){
            vector<int> vec;
            for(int j=0;j<=10001;j++){
                vec.push_back(-1);
            }   
            dp.push_back(vec);
        }
        
        int ans = 0;
        solve(rods, dp, 0, 0, 0, size);
        ans = max(ans, dp[0][5000]);
        return ans;
    }
};