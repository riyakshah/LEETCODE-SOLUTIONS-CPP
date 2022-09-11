class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            int m=triangle[i].size();
            for(int j=0;j<m;j++){
                if(j>0){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                //ans=min(ans,dp[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
        
    }
};
