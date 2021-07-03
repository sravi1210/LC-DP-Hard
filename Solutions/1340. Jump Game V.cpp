/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    void solve(vector<int> &dp, vector<int> &arr, int d, int index){
        int size = arr.size();
        if(index>=size || index<0){
            return;
        }
        if(dp[index] != -1){
            return;
        }
        int left = max(0, index-d);
        int right = min(size-1, index+d);
        int leftmax = 0;
        int rightmax = 0;
        for(int i=index-1;i>=left;i--){
            if(arr[i] >= arr[index]){
                break;
            }
            else{
                if(dp[i] == -1){
                    solve(dp, arr, d, i);
                }
                leftmax = max(leftmax, 1+dp[i]);
            }
        }
        
        for(int i=index+1;i<=right;i++){
            if(arr[i] >= arr[index]){
                break;
            }
            else{
                if(dp[i] == -1){
                    solve(dp, arr, d, i);
                }
                rightmax = max(rightmax, 1+dp[i]);
            }
        }
        dp[index] = max(leftmax, rightmax);
        return; 
    }
    
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp;
        int size = arr.size();
        for(int i=0;i<size;i++){
            dp.push_back(-1);
        }
        int maxy = 0;
        for(int i=0;i<size;i++){
            if(dp[i] == -1){
                solve(dp, arr, d, i);
            }
            maxy = max(maxy, dp[i]);
        }
        return 1+maxy;
    }
};