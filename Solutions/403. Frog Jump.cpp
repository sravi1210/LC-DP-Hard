/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

class Solution {
public:
    bool canCross(vector<int>& nums) {
        int size = nums.size();
        
        unordered_map<pair<int,int>,int, hash_pair> vis;  
        deque<pair<int,int>> dq;
        unordered_map<int,int> stone;

        int last = nums[size-1];
        
        for(int i=0;i<size;i++){
            stone[nums[i]] = 1;
        }
        
        dq.push_back({0, nums[0]});
        vis[{0, nums[0]}] = 1;
        
        while(!dq.empty()){
            pair<int,int> state = dq.front();
            dq.pop_front();
            
            int speed = state.first;
            int dest = state.second;
            if(dest == last){
                return true;
            }
            
            for(int go=-1;go<=1;go++){
                int new_dest = dest + speed + go;
                if(new_dest >= 0 && stone.find(new_dest)!=stone.end()){
                    int new_speed = speed + go;
                    if(new_dest == last){
                        return true;
                    }
                    if(vis.find({new_speed, new_dest}) == vis.end()){
                        dq.push_back({new_speed, new_dest});
                        vis[{new_speed, new_dest}] = 1;
                    }
                }
            }
        }
        
        return false;
    }
};