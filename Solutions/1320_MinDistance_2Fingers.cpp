/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minimumDistance(string word) {
        int len = word.length();
        vector<vector<vector<int>>> dp;
        for(int i=0;i<26;i++){
            vector<vector<int>> arr;
            for(int j=0;j<26;j++){
                vector<int> vec;
                for(int k=0;k<len;k++){
                    vec.push_back(0);
                }
                arr.push_back(vec);
            }
            dp.push_back(arr);
        }
        for(int k=len-1;k>=0;k--){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    int lx = i/6;
                    int ly = i%6;
                    int rx = j/6;
                    int ry = j%6;

                    int ch = word[k] - 'A';
                    int wx = ch/6;
                    int wy = ch%6;

                    if(k == len-1){
                        int left = abs(lx-wx) + abs(ly-wy);
                        int right = abs(rx-wx) + abs(ry-wy);
                        dp[i][j][k] = min(left, right);
                    }
                    else{
                        int left = abs(lx-wx) + abs(ly-wy) + dp[ch][j][k+1];
                        int right = abs(ry-wy) + abs(rx-wx) + dp[i][ch][k+1];
                        dp[i][j][k] = min(left, right);
                    }  
                }
            }
        }
        
        int miny = INT_MAX;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                miny = min(miny, dp[i][j][0]);
            }
        }
        
        
        return miny;
    }
};