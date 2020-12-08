/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> mp;
        deque<pair<int, int>> dq;
        int gMinDays = n;
        dq.push_back({n, 0});
        mp[n] = 0;
        while(!dq.empty()){
            pair<int, int> state = dq.front();
            dq.pop_front();
            int oranges_left = state.first;
            int days_taken = state.second;
            if(oranges_left == 0){
                gMinDays = min(gMinDays, days_taken);
                continue;
            }
            if(days_taken+1 < gMinDays){
                if((mp.find(oranges_left-1) == mp.end()) || (mp[oranges_left-1] > days_taken+1)){
                    mp[oranges_left-1] = days_taken+1;
                    dq.push_back({oranges_left-1, days_taken+1});
                }
                if(oranges_left%2 == 0){
                    if((mp.find(oranges_left-(oranges_left/2)) == mp.end()) || (mp[oranges_left-(oranges_left/2)] > days_taken+1)){
                        mp[oranges_left-(oranges_left/2)] = days_taken+1;
                        dq.push_back({oranges_left-(oranges_left/2), days_taken+1});
                    }
                }
                if(oranges_left%3 == 0){
                   if((mp.find(oranges_left-(2*(oranges_left/3))) == mp.end()) || (mp[oranges_left-(2*(oranges_left/3))] > days_taken+1)){
                        mp[oranges_left-(2*(oranges_left/3))] = days_taken+1;
                        dq.push_back({oranges_left-(2*(oranges_left/3)), days_taken+1});  
                   }
                }
            }
        }

        return gMinDays;
    }
};