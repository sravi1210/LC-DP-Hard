/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int longestDecomposition(string text) {
        int len = text.length();
        
        
        int Lstart = 0;
        int Lend = len/2;
        int Rstart = len/2;
        int Rend = len-1;
        
        if(len%2!=0){
            Rstart = len/2 + 1;
            Lend = len/2 - 1;
        }
        else{
            Rstart = len/2;
            Lend = len/2 - 1;
        }
        string s = text.substr(Lstart, len/2);
        string t = text.substr(Rstart, len/2);
        reverse(t.begin(), t.end());
        
        int count = 0;
        string a = "";
        string b = "";
        for(int i=0;i<len/2;i++){
            a = a + s[i];
            b = t[i] + b;
            if(a == b){
                count += 2;
                a = "";
                b = "";
            }
        }
        if(a == "" && len%2!=0){
            count+=1;
        }
        else if(a != ""){
            count+=1;
        }
        return count;
    }
};