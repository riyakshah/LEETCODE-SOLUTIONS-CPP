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
    bool helper(TreeNode* root,int mini,int maxi){
        if(!root){
            return 1;
        }
        if(root->val>maxi || root->val<mini){
            return 0;
        }
        if(root->val==INT_MIN){
            if(root->left){
                return 0;
            }
        return helper(root->right,(root->val)+1,maxi );     
        }
        if(root->val==INT_MAX){
            if(root->right){
                return 0;
            }
            return helper(root->left,mini,(root->val)-1);
        }
        return helper(root->left,mini,(root->val)-1) && helper(root->right,(root->val)+1,maxi);
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return helper(root,INT_MIN,INT_MAX);
        
    }
};
