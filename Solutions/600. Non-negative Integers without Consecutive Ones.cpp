/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int findIntegers(int num) {
        string binary = "";
        long long int val = (long long int)num;
        long long int maxL = 4294967296;
        bool first = true;
        int len = 0;
        while(maxL > 0){
            if(val >= maxL){
                binary = binary + "1";
                if(first){
                    first = false;
                }
                val -= maxL;
                len++;
            }
            else{
                if(!first){
                    binary = binary + "0";
                    len++;
                }
            }
            maxL = maxL/2;
        }
        /*Main Concept*/
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);
        for(int i=2;i<=32;i++){
            dp.push_back(dp[i-1] + dp[i-2]);    //for f bits take f-1|'0' or f-2|'01' bits into consideration
        }
        
        int answer = 0;
        char prevBit = '?';
        
        for(int i=0;i<len;i++){
            char currBit = binary[i];
            if(prevBit == '?'){
                answer += dp[len-1-i]; 
            }
            else if(prevBit == '1' && currBit == '1'){
                answer += dp[len-1-i];
                return answer;
            }
            else if(currBit == '1'){
                answer += dp[len-1-i];
            }
            prevBit = currBit;
        }
        
        return answer+1;
    }
};