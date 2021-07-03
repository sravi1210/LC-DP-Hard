/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        deque<pair<int,int>> que;
        vector<vector<int>> dp;

        int all_visited=0;
        int dmax = pow(2, n);
        
        for(int i=0;i<n;i++){
            vector<int> vec;
            for(int j=0;j<=dmax;j++){
                vec.push_back(n*n);
            }
            dp.push_back(vec);
        }
        
        for(int i=0;i<n;i++){
            all_visited += pow(2, i);   //for say 5 bit 11111.
        }
        
        for(int i=0;i<n;i++){
            int curr = i;
            int visited = pow(2, i); //set the i-th bit.
            int nodes = 1;
            que.push_back({curr, visited});
            dp[curr][visited] = nodes;
            // cout<<"("<<curr<<" "<<nodes<<" "<<visited<<") ";
        }  
        
        while(!que.empty()){
            pair<int, int> state = que.front();
            que.pop_front();
            int curr = state.first;
            int visited = state.second;
            int nodes = dp[curr][visited];

            if(visited == all_visited){
                return nodes-1;
            }
            
            int size = graph[curr].size();

            for(int i=0;i<size;i++){
                int index = graph[curr][i];
                int new_visited = visited;
                new_visited = (new_visited | (1<<index));
                
                if(nodes + 1 < dp[index][new_visited]){
                    dp[index][new_visited] = nodes + 1;
                    que.push_back({index, new_visited});
                    cout<<"("<<index<<" "<<nodes+1<<" "<<new_visited<<") ";
                }              
            } 
        }
        return 0;
    }
};