/**
 *    author:  sravi1210
 *    created: 06.03.2021 18:20:21       
**/

class Solution {
public:
    
    bool check(vector<int> &nums, long long int total, int m, long long int &sum){
        int par = 0;
        int size = nums.size();
        long long int curr = 0;
        for(int i=0;i<size;i++){
            curr += (long long int)nums[i];
            if(curr > total){
                par++;
                sum = max(sum, curr-(long long int)nums[i]);
                curr = (long long int)nums[i];
            }
        }
        if(curr>0){
            sum = max(curr, sum);
            par++;
        }
        
        if(par> m){
            return false;
        }
        return true;    
    }
    
    int splitArray(vector<int>& nums, int m) {
        //O(N*N*M) time comlexity with O(NM) space complexity solution using DP.
        //Or A Solution with binary approach with O(N*log(sum)) time complexity since minimum can be (max of array) and maximum be (sum of array).
        
        int size = nums.size();
        long long int start = nums[0];
        long long int end = 0;
        for(int i=0;i<size;i++){
            end+=(long long int)nums[i];
            start = max(start, (long long int)nums[i]);
        }
        if(m == 1){
            return end;
        }
        long long int result = end;
        while(start <= end){
            long long int mid = (start+end)/2;
            long long int sum = 0;
            if(check(nums, mid, m, sum)){
                end = mid-1;
                result = sum;
            }
            else{
                start = mid+1;
            }   
        }
        return (int)result;
    }
};