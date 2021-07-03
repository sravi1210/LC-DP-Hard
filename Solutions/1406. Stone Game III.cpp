/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int bob(vector<int> &stoneValue, vector<int> &dp, int sum, int index){
        int size = stoneValue.size();
        if(index<0 || index>=size){
            return -1;
        }
        if(dp[index] != INT_MIN){
            return dp[index];
        }
        int last = min(index+2, size-1);
        int value = 0;
        int max_value = INT_MIN;
        for(int i=index;i<=last;i++){
            value+=stoneValue[i];
            int res = 0;
            if(i+1<size && dp[i+1] == INT_MIN){
                res = alice(stoneValue, dp, sum-value, i+1);
            }
            else if(i+1<size && dp[i+1] != INT_MIN){
                res = dp[i+1];
            }
            max_value = max(max_value, (sum-res));
        }
        
        dp[index] = max_value;
        return dp[index];
    }
    
    int alice(vector<int> &stoneValue, vector<int> &dp, int sum, int index){
        int size = stoneValue.size();
        if(index<0 || index>=size){
            return -1;
        }
        if(dp[index] != INT_MIN){
            return dp[index];
        }
        int last = min(index+2, size-1);
        int value = 0;
        int max_value = INT_MIN;
        for(int i=index;i<=last;i++){
            value+=stoneValue[i];
            int res = 0;
            if(i+1<size && dp[i+1] == INT_MIN){
                res = bob(stoneValue, dp, sum-value, i+1);
            }
            else if(i+1<size && dp[i+1]!=INT_MIN){
                res = dp[i+1];
            }
            max_value = max(max_value, (sum-res));
        }
        
        dp[index] = max_value;
        return dp[index];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int size = stoneValue.size();
        vector<int> dp;
        int sum = 0;
        int index = 0;
        for(int i=0;i<size;i++){
            dp.push_back(INT_MIN);
            sum+=stoneValue[i];
        }
        
        alice(stoneValue, dp, sum, index);
        if(dp[0] == sum-dp[0]){
            return "Tie";
        }
        if(dp[0] > sum-dp[0]){
            return "Alice";
        }
        else{
            return "Bob";
        }
    }
};