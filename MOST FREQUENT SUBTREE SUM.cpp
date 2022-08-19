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
    unordered_map<int,int> umap;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int l=helper(root->left);
        int r=helper(root->right);
        int sum=l+r+(root->val);
        umap[sum]++;
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
       helper(root);
        int maxi=INT_MIN;
        vector<int> ans;
        for(auto it=umap.begin();it!=umap.end();it++){
            if(it->second>maxi){
                maxi=it->second;
            }
        }
        for(auto it=umap.begin();it!=umap.end();it++){
            if(it->second==maxi){
                ans.push_back(it->first);
            }
        }
        
        return ans;
        
        
    }
};
