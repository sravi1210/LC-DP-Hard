/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    bool bob(vector<int> &dp, vector<int> pSquare, int value){
        if(dp[value] != -1){
            if(dp[value] == 1){
                return true;
            }
            return false;
        }
        
        int size = pSquare.size();
        for(int i=0;i<size;i++){
            if(pSquare[i] == value){
                dp[value] = 1;
                return true;
            }    
            else if(pSquare[i] > value){
                break;
            }
            else{
                int next_value = value - pSquare[i];
                if(dp[next_value] == -1){
                    bob(dp, pSquare, next_value);
                }
                if(dp[next_value] == 0){
                    dp[value] = 1;
                    return true;
                }
            }
        }
        dp[value] = 0;
        return false;
    }

    bool alice(vector<int> &dp, vector<int> &pSquare, int value){
        if(dp[value] != -1){
            if(dp[value] == 1){
                return true;
            }
            return false;
        }
        
        int size = pSquare.size();
        for(int i=0;i<size;i++){
            if(pSquare[i] == value){
                dp[value] = 1;
                return true;
            }    
            else if(pSquare[i] > value){
                break;
            }
            else{
                int next_value = value - pSquare[i];
                if(dp[next_value] == -1){
                    bob(dp, pSquare, next_value);
                }
                if(dp[next_value] == 0){
                    dp[value] = 1;
                    return true;
                }
            }
        }
        dp[value] = 0;
        return false;
    }
    
    bool winnerSquareGame(int n) {
        vector<int> dp;
        for(int i=0;i<=n;i++){
            dp.push_back(-1);
        }
        dp[1] = 1;
        
        vector<int> pSquare;
        for(int i=1;i<1000;i++){
            if((i*i) <= n){
                pSquare.push_back(i*i);
            }
        }
        
        bool check = alice(dp, pSquare, n);
        return check;
    }
};