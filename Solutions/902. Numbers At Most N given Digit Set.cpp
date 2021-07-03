/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int convertStringtoNum(string s){
        switch(s[0]){
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            default:
                return 0;
        }
        return 0;
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int size = D.size();
        int answer = 0;
        vector<int> digits;
        int len=0;
        while(N>0){
            int rem = N%10;
            digits.push_back(rem);
            N = N/10;
            len++;
        }
        reverse(digits.begin(), digits.end());
        for(int i=1;i<len;i++){
            int prod = 1;
            int j=i;
            while(j>0){
                prod = prod * size;
                j--;
            }
            answer += prod;
        }
        int equal = 0;
        for(int i=0;i<len;i++){
            int dig = digits[i];
            int smaller = 0;
            equal = 0;
            for(int j=0;j<size;j++){
                int num = convertStringtoNum(D[j]);
                if(num < dig){
                    smaller++;
                }
                else if(num == dig){
                    equal++;
                }
            }
            answer += smaller * pow(size,(len-1-i));
            if(equal == 0){
                break;
            }
        }
        if(equal!=0){
            answer++;
        }
        
        return answer;
    }
};