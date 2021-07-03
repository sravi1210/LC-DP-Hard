/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int solve(vector<int> A, int cnt){
        int n = A.size();
        vector<vector<int>> dp;
        for(int i=0;i<n+1;i++){
            vector<int> vec;
            for(int j=0;j<=cnt+1;j++){
                vec.push_back(INT_MIN);
            }
            dp.push_back(vec);
        }
        
        for(int i=0;i<n+1;i++){
            dp[i][0] = 0;
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=min(cnt, (i/2)+1);j++){
                dp[i+1][j] = max(dp[i][j], A[i] + ((i==0)?0:dp[i-1][j-1]));
            }
        }
        return dp[n][cnt];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int N = slices.size();
        return max(solve(vector<int>(slices.begin(), slices.end()-1), N/3),
                  solve(vector<int>(slices.begin()+1, slices.end()), N/3));
    }
};