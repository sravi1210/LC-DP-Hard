/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> dp;
        for(int i=0;i<len;i++){
            vector<int> vec;
            for(int j=0;j<len;j++){
                vec.push_back(-1);
                if(i == j){
                    vec[j] = 0;
                }
            }
            dp.push_back(vec);
        }
        
        
        for(int size = 2;size<=len;size++){
            for(int index=0;index+size-1<len;index++){
                int start = index;
                int end = index+size-1;
                if(size == 2){
                    if(s[start] == s[end]){
                        dp[start][end] = 0;
                    }
                    else{
                        dp[start][end] = 1;
                    }
                    continue;
                }
                if(s[start] == s[end]){
                    dp[start][end] = dp[start+1][end-1];
                }
                else{
                    dp[start][end] = 1 + min(dp[start+1][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};