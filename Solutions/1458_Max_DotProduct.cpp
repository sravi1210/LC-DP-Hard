/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int findmax(int a, int b, int c, int d, int e){
        return max(a, max(b, max(c, max(d, e))));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        vector<vector<int>> dp;
        for(int i=0;i<=l1;i++){
            vector<int> vec;
            for(int j=0;j<=l2;j++){
                vec.push_back(INT_MIN);
            }
            dp.push_back(vec);
        }
        
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                int a = nums1[i]*nums2[j];
                int b = a;
                if(dp[i+1][j+1] != INT_MIN){
                    b += dp[i+1][j+1];  
                }
                dp[i][j] = findmax(a, b, dp[i+1][j], dp[i][j+1], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};