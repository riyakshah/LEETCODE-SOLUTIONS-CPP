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
    bool isSymmetrical(TreeNode* l,TreeNode* r){
        if(!l && !r){
            return 1;
        }
        if(!l || !r || l->val!=r->val ){
            return 0;
        }
        return (isSymmetrical(l->left,r->right) && isSymmetrical(l->right,r->left));

    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return 1;
        }

        TreeNode* l=root->left;
       TreeNode* r=root->right;
       return isSymmetrical(l,r);
        
    }
};
