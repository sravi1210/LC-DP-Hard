/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class TreeAncestor {
private:
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent) {  
        int depth = 16; //this is  called bit-lifting as log2(50000) ~ 16 time complexity(O(NlogN + QlogN))
        
        for(int i=0;i<n;i++){
            vector<int> vec;
            for(int j=0;j<depth;j++){
                vec.push_back(-1);
            }
            this->dp.push_back(vec);
        }
        
        //dp[i][j] means i's 2^j-th parent 
        
        for(int ht=0;ht<depth;ht++){
            for(int i=0;i<n;i++){
                if(ht==0){
                    this->dp[i][ht] = parent[i];
                }
                else{
                    if(dp[i][ht-1] == -1){
                        dp[i][ht] = -1;
                    }
                    else{
                        dp[i][ht] = dp[dp[i][ht-1]][ht-1]; //for 2^jth parent take (2^jth-1)th (2^jth-1) parent.
                    }
                }
            }
        } 
    }
    
    int getKthAncestor(int node, int k) {
        for(int ht=15;ht>=0;ht--){
            int jump = (1<<ht);      //2^j
            if((k & jump) == jump){     //k>=jump
                k^= jump;      //k-=jump
                if(node == -1){
                    return -1;
                }
                node = dp[node][ht];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */