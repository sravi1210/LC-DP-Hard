/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

/*
Approach of the solution is BFS with memoization of state.first, state = {value_reached, operation it took}
for difference of abs(target-value_Reached) value increase by x*x*x*x.. upto it just increases target and is
just less than target, push in deque if that value is not reached or is reached but operation took is less 
than previous reach.
Base Condition - For difference<=x take for x/2 value :
for eg if x = 5, then
0 - 0
1 - x/x, ie 1
2 - x/x + x/x, ie 3
3 - x - x/x - x/x, ie 4
4 - x - x/x, ie 2
5 - x, ie 1
*/

#define ll long long
class Solution {
public:
    int leastOpsExpressTarget(int xx, int tar) {
        ll target  = (ll)tar;
        ll x = (ll)xx; 
        deque<pair<ll, ll>> dq;
        dq.push_back({0,0});
        unordered_map<ll,ll> mp;
        mp[0] = 0;
        
        ll answer = 2*target + 1;
        
        while(!dq.empty()){
            pair<ll, ll> state = dq.front();
            dq.pop_front();
            ll num = state.first;
            ll opt = state.second;

            // cout<<"{"<<num<<" "<<opt<<"} ";
            
            if(num == target){
                answer = min(answer, opt);
                continue;
            }
            
            else if(abs(num-target) <= x){
                if(abs(num - target) == x){
                    if(opt == 0){
                        answer = min(answer, opt);
                        continue;
                    }
                    else{
                        answer = min(answer, opt + 1);
                        continue;
                    }
                }
                else{
                    ll diff = abs(num-target);
                    if(diff <= x/2){
                        if(opt == 0){
                            answer = min(answer, (2*diff - 1));
                            continue;
                        }
                        else{
                            answer = min(answer, (opt + (2*diff)));
                            continue;
                        }
                    }
                    else{
                        diff = x - diff;
                        if(opt == 0){
                            answer = min(answer, (2*diff));
                            continue;
                        }
                        else{
                            answer = min(answer, (opt + 1 + (2*diff)));
                            continue;
                        }
                    }
                }
            }
            
            else{
                ll diff = abs(target - num);
                ll count = 1;
                ll ans = x;
                while(ans < diff){
                    count += 1;
                    ans *= x;
                }

                if(ans == diff){
                    if(opt == 0){
                        answer = min(answer, count-1);
                    }
                    else{
                        answer = min(answer, opt+count);
                    }
                }
                if(num < target){
                    if(opt == 0){
                        if((count-2) < answer){
                            if((mp.find(num+(ans/x)) == mp.end()) || (mp[num+(ans/x)] > count-2)){ 
                                mp[num+(ans/x)] = count-2;
                                dq.push_back({num+(ans/x), count-2});
                            }
                        }
                        if((count-1) < answer){
                            if((mp.find(num+ans) == mp.end()) || (mp[num+ans] > count-1)){
                                mp[num+ans] = count-1;
                                dq.push_back({num+ans, count-1});
                            }
                        }
                    }
                    else{
                        if((opt+count-1) < answer){
                            if((mp.find(num+(ans/x)) == mp.end()) || (mp[num+(ans/x)] > opt+count-1)){
                                mp[num+(ans/x)] = opt+count-1;
                                dq.push_back({num+(ans/x), opt+count-1});
                            }
                        }
                        if((opt+count) < answer){
                            if((mp.find(num+ans) == mp.end()) || (mp[num+ans] > opt+count)){
                                mp[num+ans] = opt+count;
                                dq.push_back({num+ans, opt+count});
                            }
                        }
                    }
                }
                else if(num > target){
                    if(opt == 0){
                        if((count-2) < answer){
                            if((mp.find(num-(ans/x)) == mp.end()) || (mp[num-(ans/x)] > count-2)){ 
                                mp[num-(ans/x)] = count-2;
                                dq.push_back({num-(ans/x), count-2});
                            }
                        }
                        if((count-1) < answer){
                            if((mp.find(num-ans) == mp.end()) || (mp[num-ans] > count-1)){
                                mp[num-ans] = count-1;
                                dq.push_back({num-ans, count-1});
                            }
                        }
                    }
                    else{
                        if((opt+count-1)<answer){
                            if((mp.find(num-(ans/x)) == mp.end()) || (mp[num-(ans/x)] > opt+count-1)){
                                mp[num-(ans/x)] = opt+count-1;
                                dq.push_back({num-(ans/x), opt+count-1});
                            }
                        }
                        if((opt+count) <answer){
                            if((mp.find(num-ans) == mp.end()) || (mp[num-ans] > opt+count)){
                                mp[num-ans] = opt+count;
                                dq.push_back({num-ans, opt+count});
                            }
                        }
                    }
                }
            }
        }
        
        return (int)answer;
    }
};