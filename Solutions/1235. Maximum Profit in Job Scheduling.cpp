/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        /*
            1. O(NlogN) solution.
            2. Start from back and use binary search for endTime equal to startTime in the vector, if not, then find
            startTime greater than endTime in the vector, and add to profit, if not leave the profit unchanged, also
            for every index do check the index+1 for the maximum because it may happen that for certain indexes, 
            maximum is achieved by leaving current index and starting from index+1 and so on, and will also be useful
            for evaluating maximas in future cases.
        */
        
        int size = startTime.size();
        vector<pair<int, pair<int,int>>> dp;
        
        for(int i=0;i<size;i++){
            dp.push_back({startTime[i], {endTime[i], profit[i]}});
        }
        sort(dp.begin(), dp.end());
        vector<int> startOnly;
        unordered_map<int,int> mp;
        
        for(int i=0;i<size;i++){
            startOnly.push_back(dp[i].first);   
        }
        
        // for(int i=0;i<size;i++){
        //     cout<<"("<<dp[i].first<<" "<<dp[i].second.first<<" "<<dp[i].second.second<<") ";
        // }

        for(int i=size-1;i>=0;i--){
            
            int start = dp[i].first;
            int end = dp[i].second.first;
            int pro = dp[i].second.second;
            
            bool exist = binary_search(startOnly.begin(), startOnly.end(), end);
            
            if(exist){
                pro = pro + mp[end];
            }
            else{
                int index = upper_bound(startOnly.begin(), startOnly.end(), end) - startOnly.begin();
                if(index != size){
                    end = startOnly[index];
                    pro = pro + mp[end];
                }
            }
            
            if(i+1<size){
                pro = max(pro, mp[dp[i+1].first]);
            }
            mp[start] = pro;
        }
        
        return mp[startOnly[0]];   
    }
};