class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                int ind=i+j;
                if(ind<n){
                dp[ind]=min(dp[ind],1+dp[i]);
                }
                else{
                    break;
                }
            }
        }
        return dp[n-1];
        
    }
};
