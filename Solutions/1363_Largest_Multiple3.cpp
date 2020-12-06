/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int size = digits.size();
        vector<int> mp;
        for(int i=0;i<=9;i++){
            mp.push_back(0);
        }
        
        int sum = 0;
        for(int i=0;i<size;i++){
            mp[digits[i]]++;
            sum+=digits[i];
        }
        if(sum%3!=0){
            int rem = sum%3;
            if(rem == 1){
                if(mp[1] >= 1){
                    mp[1]--;
                }
                else if(mp[4] >= 1){
                    mp[4]--;
                }
                else if(mp[7] >= 1){
                    mp[7]--;
                }
                else if(mp[2] >= 2){
                    mp[2] -= 2; 
                }
                else if(mp[5] >= 2){
                    mp[5] -= 2;
                }
                else if(mp[8] >= 2){
                    mp[8] -= 2;
                }
                else{
                    return "";
                }
            }
            else if(rem == 2){
                if(mp[2] >= 1){
                    mp[2]--;
                }
                else if(mp[5] >= 1){
                    mp[5]--;
                }
                else if(mp[8] >= 1){
                    mp[8]--;
                }
                else if(mp[1] >= 2){
                    mp[1] -= 2;
                }
                else if(mp[4] >= 2){
                    mp[4] -= 2;
                }
                else if(mp[7] >= 2){
                    mp[7] -= 2;
                }
                else{
                    return "";
                }
            }
        }
        
        string s = "";
        for(int i=9;i>0;i--){
            int count = mp[i];
            string t = to_string(i);
            while(count>0){
                s = s + t;
                count--;
            }
        }
        
        if(s.length() == 0){
            if(mp[0] > 0){
                return "0";
            }
            else{
                return "";
            }
        }
        else{
            int count = mp[0];
            string t = "0";
            while(count>0){
                s = s + t;
                count--;
            }
        }
        
        
        return s;
        
        
        
        
        
    }
};