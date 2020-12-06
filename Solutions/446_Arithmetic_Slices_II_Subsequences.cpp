/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        if(size<3){
            return 0;
        }
        
        unordered_map<long long int ,map<long long int, long long int>> mp;
        long long int ans = 0;
        
        for(long long int i=1;i<size;i++){
            for(long long int j=i-1;j>=0;j--){
                long long int diff = (long long int)A[i] - (long long int)A[j];
                if(mp[j].find(diff) != mp[j].end()){
                    ans += mp[j][diff];
                    mp[i][diff] += mp[j][diff];
                }
                mp[i][diff] += 1;
            }
        }
        return ans;
    }
};
