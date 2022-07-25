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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root){
            return ans;
        }
        q.push(root);
        ans.push_back({root->val});
        while(!q.empty()){
            vector<int> vect;
            int n= q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
            if(t->left){
                q.push(t->left);
                vect.push_back(t->left->val);
            }
            if(t->right){
                q.push(t->right);
                vect.push_back(t->right->val);
            }
            q.pop();
                
        }
            if(vect.size()){
            ans.push_back(vect);
            }
        }
        return ans;
        
    }
};
