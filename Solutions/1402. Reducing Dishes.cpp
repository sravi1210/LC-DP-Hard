/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int curr_sum = 0;
        int sum = 0;
        sort(satisfaction.begin(), satisfaction.end());
        int size = satisfaction.size();
        for(int i=size-1;i>=0;i--){
            curr_sum+=satisfaction[i];
            if(curr_sum < 0){
                break;
            }
            sum += curr_sum;
        }
        return sum;
    }
};