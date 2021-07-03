/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelope) {
        int size = envelope.size();
        if(size == 0){
            return 0;
        }
        vector<pair<int,int>> env;
        vector<int> dp;
        for(int i=0;i<size;i++){
            env.push_back({envelope[i][0], envelope[i][1]});
            dp.push_back(1);
        }
        sort(env.begin(), env.end());
        
        for(int i=size-1;i>=0;i--){
            int width = env[i].first;
            int height = env[i].second;
            pair<int,int> check = {width, height};
            // int index = upper_bound(env.begin(), env.end(), check) - env.begin();
            int index = -1;
            
            int value = -1;
            for(int j=i+1;j<size;j++){
                if(env[j].second > height && env[j].first > width){
                    index = max(index, j);
                    value = max(value, dp[j]);
                }
            }
            if(index == -1){
                continue;
            }
            else{
                dp[i] += value;
            }
        }
        
        int maxy = 1;
        for(int i=0;i<size;i++){
            maxy = max(maxy, dp[i]);
        }
        return maxy;
    }
};