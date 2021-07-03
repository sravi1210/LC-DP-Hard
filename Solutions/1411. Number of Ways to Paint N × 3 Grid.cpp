/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int numOfWays(int n) {
        long long numTwo = 6;
        long long numThree = 6;
        long long mod = 1000000007;
        vector<long long> dp;
        dp.push_back(numTwo+numThree);
        if(n == 0){
            return n;
        } 
        for(int i=2;i<=n;i++){
            numTwo = numTwo%mod;
            numThree = numThree%mod;
            long long two = (numTwo*3)%mod + (numThree*2)%mod;
            long long three = (numTwo*2)%mod + (numThree*2)%mod;
            numTwo = two;
            numThree = three;
            long long ans = (numTwo + numThree)%mod;
            dp.push_back(ans);
        }
        
        return dp[n-1];
    }
};