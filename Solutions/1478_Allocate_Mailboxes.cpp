/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        int size = houses.size();
        if(K>=size){
            return 0;
        }
        
        sort(houses.begin(), houses.end());
        vector<vector<vector<int>>> dp;
        
        for(int i=0;i<=K;i++){
            vector<vector<int>> arr;
            for(int j=0;j<size;j++){
                vector<int> vec;
                for(int k=0;k<size;k++){
                    vec.push_back(-1);
                }
                arr.push_back(vec);
            }
            dp.push_back(arr);
        }
        
        for(int k=1;k<=K;k++){
            for(int srt=size-1;srt>=0;srt--){
                int count = INT_MAX;
                for(int par=srt;par<size;par++){
                    if(k==1){
                        if(k>=par-srt+1){
                            dp[k][srt][par] = 0;
                        }
                        else{
                            int first = houses[srt];
                            int last = houses[par];
                            if(par-srt+1 == 2){
                                dp[k][srt][par] = last-first;
                            }
                            else{
                                dp[k][srt][par] = (last-first) + dp[k][srt+1][par-1];
                            }
                        }
                    }
                    else{
                        if(par+1<size && dp[1][srt][par] != -1 && dp[k-1][par+1][size-1]!=-1){
                            count = min(count, dp[1][srt][par] + dp[k-1][par+1][size-1]);
                        }
                    }
                } 
                if(count!=INT_MAX && k>1){
                    dp[k][srt][size-1] = count;
                }
            }
        }
        
        /* For debugging purpose */
        
        // for(int k=1;k<=K;k++){
        //     for(int i=size-1;i>=0;i--){
        //         for(int j=i;j<size;j++){
        //             cout<<"("<<k<<", "<<i+1<<", "<<j+1<<" -> "<<dp[k][i][j]<<")"<<" ";
        //         }
        //     }
        // }
        
        return dp[K][0][size-1];
    }
};