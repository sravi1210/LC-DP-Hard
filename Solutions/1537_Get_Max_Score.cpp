/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

#define ll long long
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int l1=0,l2=0;
        ll res=0;
        ll sum1=0;
        ll sum2=0;
        ll mod = 1000000007;
        while(l1<len1 && l2<len2){
            if(nums1[l1] == nums2[l2]){
                res += max(sum1, sum2) + (ll)nums1[l1];
                sum1=0;
                sum2=0;
                l1++;
                l2++;
            }
            else if(nums1[l1] > nums2[l2]){
                sum2+=(ll)nums2[l2];
                l2++;
            }
            else{
                sum1+=(ll)nums1[l1];
                l1++;
            }
        }
        
        while(l1<len1){
            sum1+=(ll)nums1[l1];
            l1++;
        }
        while(l2<len2){
            sum2+=(ll)nums2[l2];
            l2++;
        }
        res = res + max(sum1, sum2);
        res %= mod;
        
        return (int)res;
    }
};