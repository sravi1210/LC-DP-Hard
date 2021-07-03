/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int racecar(int target) {
        deque<pair<long long int, pair<long long int, long long int>>> dq;
        dq.push_back({0, {0, 1}});
        int answer = 0;
        
        while(!dq.empty()){
            pair<long long int, pair<long long int, long long int>> pp = dq.front();
            dq.pop_front();
            long long int pos = pp.second.first;
            long long int speed = pp.second.second;
            long long int len = pp.first;
            
            if(pos == target){
                return (int)len;
            }
            //Case 'A' :
            dq.push_back({len+1,{pos+speed, speed*2}});

            //Case 'R' :
            if(speed > 0 && (pos+speed) > target){
                dq.push_back({len+1,{pos, -1}});
            }
            else if(speed < 0 && (pos+speed) < target){
                dq.push_back({len+1,{pos, 1}});
            }
            
        }
        return answer;
    }
};