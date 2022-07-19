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
    vector<TreeNode*> helper(int st, int end){
        vector<TreeNode*> ans;
        if(st>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=st;i<=end;i++){
        vector<TreeNode*> l=helper(st,i-1);
        vector<TreeNode*> r= helper(i+1,end);
        for(int j=0;j<(int)l.size();j++){
            for(int k=0;k<(int)r.size();k++){
                TreeNode* root=new TreeNode(i);
                root->left=l[j];
                root->right=r[k];
                ans.push_back(root);
            }
        }
            
    }
    return ans;

    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> temp(0);
        if(n==0){
            return temp;
        }
        return helper(1,n);
        
    }
};


