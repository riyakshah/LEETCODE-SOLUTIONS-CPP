class Solution {
public:
    void solve(int ind,vector<int> nums,vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(nums);
        }
        else{
            for(int i=ind;i<nums.size();i++){
                if(i!=ind && nums[i]==nums[ind]){
                    continue;
                }
                swap(nums[i],nums[ind]);
                solve(ind+1,nums,ans);
               // swap(nums[i],nums[ind]);
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
        
    }
};
