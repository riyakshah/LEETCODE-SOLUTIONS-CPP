class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for (unsigned int i=0; i<nums.size(); i++) {
        if ((i>0) && (nums[i]==nums[i-1]))
            continue;
        int l = i+1, r = nums.size()-1;
        while (l<r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;
            else if (s<0) l++;
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                while (l<n-1 && nums[l]==nums[l+1]) l++;
                while (r>=1 && nums[r]==nums[r-1]) r--;
                l++; r--;
            }
        }
    }
    return res;
    }
};
