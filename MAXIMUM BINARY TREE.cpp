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
    int greatest_index(int l,int r,vector<int> nums){
        int ans=INT_MIN;
        int maxi = INT_MIN;
        for(int i=l;i<=r;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ans=i;
            }
        }
        return ans;
    }
    TreeNode* helper(int l,int r, vector<int>& nums){
        if(l>r){
            return NULL;
        }
        int i = greatest_index(l,r,nums);
        TreeNode* root = new TreeNode(nums[i]);
        root->left = helper(l,i-1,nums);
        root->right = helper(i+1,r,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       int n=nums.size();
       TreeNode* root= helper(0,n-1,nums);
        return root;
        
    }
};
