class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
        }
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i],dp[i]+dp[i-1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
            }
        }
        return ans;
        
    }
};
