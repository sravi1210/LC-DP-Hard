/**
 *    author:  sravi1210
 *    created: 06.09.2020 18:20:21       
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void calculate(TreeNode* root, map<TreeNode*, int> &sumBST){
        if(root == NULL){
            return;
        }
        int sumLeft = 0;
        int sumRight = 0;
        
        if(root->left != NULL){
            calculate(root->left, sumBST);
            sumLeft = sumBST[root->left];
        }
        if(root->right!=NULL){
            calculate(root->right, sumBST);
            sumRight = sumBST[root->right];
        }
        
        sumBST[root] = root->val + sumLeft + sumRight;
        return;
    }
    
    void maxBST(TreeNode* root, map<TreeNode*, int> &sumBST, map<TreeNode*, bool> &checkBST, int &ans, map<TreeNode*, int> &minMost, map<TreeNode*, int> &maxMost){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            checkBST[root] = true;
            ans = max(ans, sumBST[root]);
            minMost[root] = root->val;
            maxMost[root] = root->val;
            return;
        }
        else if(root->left == NULL){
            maxBST(root->right, sumBST, checkBST, ans, minMost, maxMost);
            if(checkBST[root->right]){
                if(root->val < root->right->val){
                    if(root->val < minMost[root->right]){
                        minMost[root] = root->val;
                        maxMost[root] = maxMost[root->right];
                        ans = max(ans, sumBST[root]);
                        checkBST[root] = true;
                        return;
                    }
                }
            }
        }
        else if(root->right == NULL){
            maxBST(root->left, sumBST, checkBST, ans, minMost, maxMost);
            if(checkBST[root->left]){
                if(root->val > root->left->val){
                    if(root->val > maxMost[root->left]){
                        minMost[root] = minMost[root->left];
                        maxMost[root] = root->val;
                        ans = max(ans, sumBST[root]);
                        checkBST[root] = true;
                        return;
                    }
                }
            }
        }
        else{
            maxBST(root->right, sumBST, checkBST, ans, minMost, maxMost);
            maxBST(root->left, sumBST, checkBST, ans, minMost, maxMost);
            if(checkBST[root->left] && checkBST[root->right]){
                if((root->val > root->left->val) && (root->val < root->right->val)){
                    if(root->val > maxMost[root->left] && root->val < minMost[root->right]){
                        minMost[root] = minMost[root->left];
                        maxMost[root] = maxMost[root->right];
                        ans = max(ans, sumBST[root]);
                        checkBST[root] = true;
                        return;
                    }
                }
            }
        }
        checkBST[root] = false;
        return;
    }
    
    int maxSumBST(TreeNode* root) {
        map<TreeNode*, int> sumBST;
        map<TreeNode*, bool> checkBST;
        map<TreeNode*, int> minMost;
        map<TreeNode*, int> maxMost;

        if(root == NULL){
            return 0;
        }
        calculate(root, sumBST);
        int ans = 0;
        maxBST(root, sumBST, checkBST, ans, minMost, maxMost);
        return ans;
    }
};