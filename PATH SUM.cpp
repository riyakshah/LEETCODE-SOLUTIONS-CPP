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
    bool helper(TreeNode* root,int target){
       
        if(root && root->left==NULL && root->right==NULL && target-(root->val)==0){
            return 1;
        }
        else if(!root){
            return 0;
        }
        return (helper(root->left,target-(root->val))) || helper(root->right,target-(root->val));

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return helper(root,targetSum);
        
        
    }
};
