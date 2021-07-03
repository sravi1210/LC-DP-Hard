/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        if(len1 == len2){
            if(str1 == str2){
                return str1;
            }
        } 
        if(len1 > len2){
            string temp = str1;
            int len = len1;
            len1 = len2;
            str1 = str2;
            str2 = temp;
            len2 = len;
        }
        
        vector<vector<pair<int,int>>> dp;
        vector<vector<int>> mp;
        
        for(int i=0;i<=len1;i++){
            vector<pair<int,int>> vecp;
            vector<int> vec;
            
            for(int j=0;j<=len2;j++){
                pair<int,int> pp;
                vecp.push_back(pp);
                vec.push_back(0);
            }
            dp.push_back(vecp);
            mp.push_back(vec);
        }
        dp[len1][len2] = {-1,-1};
        mp[len1][len2] = 0;
        
        int len = 0;
        for(int i=len1-1;i>=0;i--){
            len+=1;
            dp[i][len2] = {i+1,len2};
            mp[i][len2] = len;
        }
        len = 0;
        for(int i=len2-1;i>=0;i--){
            len++;
            dp[len1][i] = {len1, i+1};
            mp[len1][i] = len;
        }

        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                if(str1[i] == str2[j]){
                    dp[i][j] = {i+1,j+1};
                    mp[i][j] = 1 + mp[i+1][j+1];
                }
                else{
                    int x = mp[i+1][j];
                    int y = mp[i][j+1];
                    if(x<=y){
                        dp[i][j] = {i+1, j};
                        mp[i][j] = 1 + mp[i+1][j];
                    }
                    else{
                        dp[i][j] = {i, j+1};
                        mp[i][j] = 1 + mp[i][j+1];
                    }
                }
                // cout<<"("<<i<<" "<<j<<" "<<dp[i][j]<<") ";
            }
        }
        
        int x = 0,y=0;
        string t = "";
        while(dp[x][y].first != -1){
            int nx = dp[x][y].first;
            int ny = dp[x][y].second;
            if(nx == x+1 && ny == y+1){
                t = t + str1[x];
            }
            else if(nx == x+1){
                t = t + str1[x];
            }
            else if(ny == y+1){
                t = t + str2[y];
            }
            x = nx;
            y = ny;
        }
        
        
        return t;
    }
};