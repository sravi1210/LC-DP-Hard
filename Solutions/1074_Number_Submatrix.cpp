/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 && j==0){
                    continue;
                }
                else if(i==0){
                    matrix[i][j] += matrix[i][j-1];
                }
                else if(j==0){
                    matrix[i][j] += matrix[i-1][j];
                }
                else{
                    matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
                }
            }
        }
        
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=i;j<rows;j++){
                unordered_map<int,int> mp;
                for(int k=cols-1;k>=0;k--){
                    int area = 0;
                    if(i==0 && j==0){
                        area = matrix[i][k];
                    }
                    else if(i==0){
                        area = matrix[j][k];
                    }
                    else{
                        area = matrix[j][k] - matrix[i-1][k];
                    }
                    
                    if(area == target){
                        count++;
                    }
                    int req_area = target + area;
                    if(mp.find(req_area) != mp.end()){   //to remove TLE -> unordered_map find has average of constant time.
                        count += mp[req_area];
                    }
                    mp[area]++;
                }
            }
        }
        
        return count;
    }
};