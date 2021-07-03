/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

/*
Eg : N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]

the function fun will start from root 0 (WLOG) and will go on and calculate path and total length of 
path for each child and will then update 
(root's path as 1 + path(child)) for every child and 
(root's total path length as 1 + 1*path(child) + total(child)), 
so after fun is completed at every node will contain no of paths below it and their sum of path lengths.

so vector<int> ans = [8,0,3,0,0,0] for above example.

Now, function calc will again go from root and for every child of root it will calcualate the
contribution it did into the root path and total, then subtract those contribution from the root
in temporary variable, so now
(path of child += 1 + path of temporary updated root) && 
(total of child += 1 + path of temporary updated root + total of temporary updated root). 

so vector<int> ans = [8,12,6,10,10,10] for above example.
*/

class Solution {
public:
    void fun(vector<vector<int>> &gp, unordered_map<int,pair<int,int>> &rec, int root, int parent){
        if(rec.find(root) != rec.end()){
            return;
        }    

        int size = gp[root].size();
        
        int path = 0;
        int total = 0;
        
        for(int i=0;i<size;i++){
            if(gp[root][i] != parent){
                int child = gp[root][i];
                if(rec.find(child) ==  rec.end()){
                    fun(gp, rec, child, root);
                }
                int t_total = rec[child].first;
                int t_path = rec[child].second;
                path += 1 + t_path;  
                total += 1 + t_path + t_total;
            }
        }
        rec[root] = {total, path};
        return;
    }
    
    void calc(vector<vector<int>> &gp, unordered_map<int,pair<int,int>> &rec, int root, int parent){
        int size = gp[root].size();
        
        int path = rec[root].second;
        int total = rec[root].first;
        
        for(int i=0;i<size;i++){
            if(gp[root][i] != parent){
                int child = gp[root][i];
                
                int t_total = rec[child].first;  //child path lengths and total
                int t_path = rec[child].second;
                
                int c_path = 1 + t_path;    //child's contribution in root's path and total
                int c_total = 1 + t_path + t_total;
                
                int p_path = path - c_path;  //remove child's contribution in root
                int p_total = total - c_total;
                
                int n_path  = 1 + p_path;    //extra child's record to be added
                int n_total = 1 + p_path + p_total;
                
                rec[child] = {t_total+n_total, t_path+n_path};
                calc(gp, rec, child, root);
            }
        }
        return;
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> ans;
        if(N==1){
            ans.push_back(0);
            return ans;
        }
        if(N==2){
            ans.push_back(1);
            ans.push_back(1);
            return ans;
        }
        
        vector<vector<int>> gp;
        for(int i=0;i<N;i++){
            vector<int> vec;
            gp.push_back(vec);
        }
        for(int i=0;i<N-1;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            gp[x].push_back(y);
            gp[y].push_back(x);
        }
        
        unordered_map<int, pair<int,int>> rec;
        fun(gp, rec, 0, -1);
        
        calc(gp, rec, 0, -1);
        
        for(int i=0;i<N;i++){
            ans.push_back(rec[i].first);
        }
        return ans;
    }
};