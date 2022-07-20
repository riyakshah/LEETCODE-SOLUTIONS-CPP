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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int targetSum,vector<int> vect){
        if(!root){
            return;
        }
        vect.push_back(root->val);
        helper(root->left,targetSum-(root->val),vect);
        helper(root->right,targetSum-(root->val),vect);
        if(root && root->right==NULL && root->left==NULL && targetSum==root->val){
            ans.push_back(vect);
        }
        vect.pop_back();
        return;
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vect;
        helper(root,targetSum,vect);
        return ans;
        
    }
};
