/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    //Logic : first fill dp[x] - which means for size of digit x. how many are there having atleast one repeating digit
    //add all dp[x] for x<len(N)
    //for length N, eg : 34357
    //for first 3 - (1-2)*10^4 - (1-2)*9*8*7*6
    //for second 4 - (3)(0-2)*10^3 - (3)(0-2)*8*7*6 | (3)(3)*10^3 
    //for third 3 - (34)(0-2)*10^2 - (34)(0-2)*7*6
    //for fourth 5 - (343)(0-5)*10^1
    //for sixth 7 - (3435)(0-7)*10^0
    //add 1 to the final answer if (any=true) ie initially atleast one digit is repeating atleast one time.
    
    int calc(int exponent){
        long value = 9 * (long)pow(10, exponent);
        long diff = 9;
        long curr = 9;
        while(exponent>0){
            diff *= curr;
            curr -= 1;
            exponent -= 1;
        }
        
        long answer = value-diff;
        return (int)answer;
    }
    int multi(int start, int size){
        int ans = 1;
        while(size>0){
            ans *= start;
            start -= 1;
            size -= 1;
        }
        return ans;
    }
    
    int numDupDigitsAtMostN(int N) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        dp.push_back(9);
        for(int i=3;i<=9;i++){
            dp.push_back(calc(i-1));
        }

        int size = 0;
        vector<int> digits;
        while(N>0){
            int rem = N%10;
            digits.push_back(rem);
            size += 1;
            N = N/10;
        }
        
        int answer = 0;
        for(int i=0;i<size;i++){
            answer += dp[i];
        }

        map<int,int> mp;
        bool any = false;
        int len=1;
        bool first = true;
        
        for(int i=size-1;i>=0;i--){
            int dig = digits[i];
            if(dig == 0){
                mp[dig]++;
            }
            else{
                int value2 = 0;
                int value1 = 0;
                int ind = 0;
                if(first){
                    ind = 1;
                }
                if(any){
                    value1 = (dig-ind)*pow(10, size-len);
                    value2 = 0;
                }
                else{
                    for(;ind<dig;ind++){
                        bool equal = false;
                        for(int j=size-1;j>i;j--){
                            if(digits[j] == ind){
                                equal = true;
                                goto here;
                            }
                        }
                        here:
                        if(equal){
                            value1 += pow(10, size-len);
                            value2 += 0;
                        }
                        else{
                            value1 += pow(10, size-len);
                            value2 += multi(10-len, size-len);
                        }
                    }
                }
                answer += value1-value2;
                mp[dig]++;
            }
            if(mp[dig] > 1){
                any = true;
            }
            if(first){
                first = false;
            }
            len++;
        }
        if(any){
            answer++;
        }
        return answer;
    }
};