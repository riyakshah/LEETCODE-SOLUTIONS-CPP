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
private:
    int result;
    int target;
public:
    void dfs(TreeNode* root, long curSum) {
        if(!root) {
            return ;
        }
        curSum += root->val;
        if(curSum == target) {
            result++;
        }
        dfs(root->left, curSum);
        dfs(root->right, curSum);
    }
    
    void traverse(TreeNode* root) {
        if(!root) {
            return ;
        }
        traverse(root->right);
        traverse(root->left);
        dfs(root, 0);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        result = 0;
        target = targetSum;
        traverse(root);
        return result;
    }
};
