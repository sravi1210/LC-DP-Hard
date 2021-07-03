/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

/*
See Submission (No reason for TLE just shit like IDE and evaluation, similar approach O(N)) for if you want 
clarity in approach this is just for passing all test cases.
*/
class Solution {
    int plus(int a, int b) {
        int div = 1e9 + 7;
        return (a + b) % div;
    }
public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        
        int a1 = 2, a2 = 1, a3 = 1, a4 = 3, a5 = 1, a6 = 0;
        for (int i = 2; i < n; i++) {
            int na1 = plus(plus(a1, a2), a3);
            int na2 = a1;
            int na3 = a2;
            int na4 = plus(plus(plus(plus(plus(a1, a2), a3), a4), a5), a6);
            int na5 = a4;
            int na6 = a5;
            
            a1 = na1;
            a2 = na2;
            a3 = na3;
            a4 = na4;
            a5 = na5;
            a6 = na6;
        }
        
        return plus(plus(plus(plus(plus(a1, a2), a3), a4), a5), a6);
    }
};