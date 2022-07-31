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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root){
            return ans;
        }
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> vect;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                if(temp->left){
                    q.push(temp->left);
                    vect.push_back(temp->left->val);
                }
                if(temp->right){
                   q.push(temp->right);
                    vect.push_back(temp->right->val);
                }
                q.pop();
            }
            if(vect.size()>0){
            ans.push_back(vect[vect.size()-1]);
                }
        }
        return ans;
        
    }
};
