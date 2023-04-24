class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        int flag=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                dp[i][i]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[j]!='0'){
                    dp[i][j]=dp[i][j-1];
                }
                if(j>0 && (s[j-1]=='1' || (s[j-1]=='2' && s[j]>='0' && s[j]<'7'))){
                    if(j>1){
                    dp[i][j]=dp[i][j]+dp[i][j-2];
                    }
                    else{
                        dp[i][j]=dp[i][j]+1;
                    }
                }
                if(dp[0][j]==0){
                    //dp[i][j]=0;
                    flag=1;
                    break;
                }

            }
            if(flag==1){
                break;
            }

        }
        if(flag==1){
            return 0;
        }
        return dp[0][n-1];
        
    }
};
