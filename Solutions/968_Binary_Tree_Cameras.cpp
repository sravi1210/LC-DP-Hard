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
    void setCover(TreeNode* root, map<TreeNode*, int> &cover, bool parent){
        if(root == NULL){
            return;
        }
        int count = 0;
        if(root->left != NULL){
            setCover(root->left, cover, true);
            count+=1;
        }
        if(root->right != NULL){
            setCover(root->right, cover, true);
            count+=1;
        }
        if(parent){
            count+=1;
        }
        cover[root] = count;
        return;
    }
    
    int setCamera(TreeNode* root, map<TreeNode*, int> &cover, map<TreeNode*, int> &camera, map<TreeNode*, int> &important){
        if(root == NULL){
            return 0;
        }
        int Lcam=-1,Rcam=-1;
        
        if(root->left != NULL){
            Lcam = 0;
            if(cover[root->left] > 1){
                Lcam = setCamera(root->left, cover, camera, important);   
            }
        }
        if(root->right!=NULL){
            Rcam = 0;
            if(cover[root->right] > 1){
                Rcam = setCamera(root->right, cover, camera, important);
            }
        }
        
        if(Rcam == 0 && Lcam == 0){
            camera[root->left] = -1;
            camera[root->right] = -1;
            camera[root] = 1;
            important[root] = 1;
            return 1;
        }
        else if(Lcam == -1){  //nothing in left 
            if(Rcam == 0){
                camera[root->right] = -1;
                camera[root] = 1;
                important[root]  = 1;
                return 1;
            }
            else{
                if(camera[root->right] == -1){
                    camera[root] = 1;
                    important[root] = -1;
                    return 1+Rcam;
                }
                else{
                    if(important[root->right] == -1){
                        camera[root] = 1;
                        important[root] = 1;
                    }
                    else{
                        camera[root] = -1;
                    }
                    return Rcam;
                }
            }
        }
        else if(Rcam == -1){   //nothing in right
            if(Lcam == 0){
                camera[root->left] = -1;
                camera[root] = 1;
                important[root] = 1;
                return 1;
            }
            else{
                if(camera[root->left] == -1){
                    camera[root] = 1;
                    important[root] = -1;
                    return 1+Lcam;
                }
                else{
                    if(important[root->left] == -1){
                        camera[root->left] = 1;
                        camera[root] = 1;
                        important[root] = 1;
                    }
                    else{
                        camera[root] = -1;
                    }
                    return Lcam;
                }
            }
        }
        else if(Lcam == 0){
            camera[root->left] = -1;
            camera[root] = 1;
            important[root] = 1;
            if(important[root->right] == -1){
                camera[root->right] = -1;
                Rcam--;
            }
            return 1+Rcam;
        }
        else if(Rcam == 0){
            camera[root->right] = -1;
            camera[root] = 1;
            important[root] = 1;
            if(important[root->left] == -1){
                camera[root->left] = -1;
                Lcam--;
            }
            return 1+Lcam;
        }
        else if(Lcam>0 && Rcam>0){
            if(camera[root->left] == 1 && camera[root->right] == 1){
                if(important[root->left] == -1 && important[root->right] == -1){
                    camera[root] = 1;
                    important[root] = 1;
                    camera[root->left] = -1;
                    camera[root->right] = -1;
                    return Lcam+Rcam-1;
                }
                else if(important[root->left] == -1){
                    camera[root->left] = -1;
                    camera[root] = 1;
                    important[root] = 1;
                    return Lcam+Rcam;
                }
                else if(important[root->right] == -1){
                    camera[root->right] = -1;
                    camera[root] = 1;
                    important[root] = 1;
                    return Lcam+Rcam;
                }
                else{
                    camera[root] = -1;
                    return Lcam+Rcam;
                }
            }
            else if(camera[root->left] == -1 && camera[root->right] == -1){
                camera[root] = 1;
                important[root] = -1;
                return 1+Lcam+Rcam;
            }
            else{
                if(camera[root->left] == 1){
                    if(important[root->left] == 1){
                        camera[root] = -1;
                        return Lcam+Rcam;
                    }
                    else{
                        camera[root] = 1;
                        important[root] = 1;
                        camera[root->left] = -1;
                        return Lcam+Rcam;
                    }
                }
                else{
                    if(important[root->right] == 1){
                        camera[root] = -1;
                        return Lcam+Rcam;
                    }
                    else{
                        camera[root] = 1;
                        important[root] = 1;
                        camera[root->right] = -1;
                        return Lcam+Rcam;
                    }
                }
            }
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        else if(root->left == NULL && root->right == NULL){
            return 1;
        }
        map<TreeNode*, int> cover;  //map to check how many nodes a given TreeNode can cover
        map<TreeNode*, int> camera; //map for if a camera is installed at TreeNode
        map<TreeNode*, int> important; //for marking the TreeNodes on which placing camera is important;
        bool parent  = false;
        setCover(root, cover, parent);

        int cam = setCamera(root, cover, camera, important);
        
        return cam;
    }
};