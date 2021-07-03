/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int cuts = k-1;
        if(cuts == 0){
            return 1;
        }
        int rows = pizza.size();
        int cols = pizza[0].length();
        long long int mod = 1000000007;
        
        vector<vector<vector<long long int>>> dp;
        
        vector<vector<int>> apples;
        
        for(int i=0;i<=cuts;i++){
            vector<vector<long long int>> arr;
            for(int j=0;j<rows;j++){
                vector<long long int> vec;
                for(int k=0;k<cols;k++){
                    vec.push_back(-1);
                }
                arr.push_back(vec);              
            }
            dp.push_back(arr);
        }
        
        for(int i=0;i<rows;i++){
            vector<int> vec;
            for(int j=0;j<cols;j++){
                vec.push_back(0);
                if(pizza[i][j] == 'A'){
                    vec[j] = 1;
                }
            }
            apples.push_back(vec);
        }
        
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(i==rows-1 && j==cols-1){
                    continue;
                } 
                else if(i == rows-1){
                    apples[i][j] += apples[i][j+1];
                }
                else if(j == cols-1){
                    apples[i][j] += apples[i+1][j];
                }
                else{
                    apples[i][j] += apples[i+1][j]+apples[i][j+1]-apples[i+1][j+1];
                }
            }
        }
        
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 cout<<apples[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        for(int c=1;c<=cuts;c++){
            for(int i=rows-1;i>=0;i--){
                for(int k=cols-1;k>=0;k--){
                    int applesInGrid = apples[i][k];
                    if(applesInGrid <= c){
                        dp[c][i][k] = -1;
                        // cout<<"(dp["<<c<<"]["<<i<<"]["<<k<<"]="<<dp[c][i][k]<<") ";
                    }
                    else{
                        if(c == 1){
                            long long int col_cut = 0;
                            long long int row_cut = 0;
                            for(int j=k+1;j<cols;j++){
                                int apples_right = apples[i][j];
                                int apples_left = apples[i][k] - apples_right;
                                if(apples_left>=1 && apples_right>=1){
                                    col_cut++;
                                }
                            }
                            for(int j=i+1;j<rows;j++){
                                int apples_down = apples[j][k];
                                int apples_up = apples[i][k] - apples_down;
                                if(apples_down>=1 && apples_up>=1){
                                    row_cut++;
                                }
                            }
                            if(row_cut + col_cut > 0){
                                dp[c][i][k] = row_cut;
                                dp[c][i][k] %= mod;
                                dp[c][i][k] += col_cut;
                                dp[c][i][k] %= mod;
                                // cout<<"(dp["<<c<<"]["<<i<<"]["<<k<<"]="<<dp[c][i][k]<<") ";
                            }
                        }
                        else{
                            long long int col_cut = -1;
                            long long int row_cut = -1;
                            for(int j=k+1;j<cols;j++){
                                int apples_right = apples[i][j];
                                int apples_left = apples[i][k] - apples_right;
                                if(apples_left>=1 && apples_right>=1 && dp[c-1][i][j] !=-1){
                                    if(col_cut == -1){
                                        col_cut = 0;
                                    }
                                    col_cut += dp[c-1][i][j];
                                    col_cut %= mod;
                                }
                            }
                            for(int j=i+1;j<rows;j++){
                                int apples_down = apples[j][k];
                                int apples_up = apples[i][k] - apples_down;
                                if(apples_down>=1 && apples_up>=1 && dp[c-1][j][k]!=-1){
                                    if(row_cut == -1){
                                        row_cut = 0;
                                    }
                                    row_cut += dp[c-1][j][k];
                                    row_cut %= mod;
                                }
                            }
                            if(row_cut != -1){
                                if(dp[c][i][k] == -1){
                                    dp[c][i][k] = 0;
                                }
                                dp[c][i][k] += row_cut;
                                dp[c][i][k] %= mod;
                            }
                            if(col_cut != -1){
                                if(dp[c][i][k] == -1){
                                    dp[c][i][k] = 0;
                                }
                                dp[c][i][k] += col_cut;
                                dp[c][i][k] %= mod;
                            }
                            // cout<<"(dp["<<c<<"]["<<i<<"]["<<k<<"]="<<dp[c][i][k]<<") ";
                        }
                    }
                } 
            }
        }
        if(dp[cuts][0][0] == -1){
            return 0;
        }
        return dp[cuts][0][0]; 
    }
};