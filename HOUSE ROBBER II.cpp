class Solution {
public:
   
    int temp(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
       vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            
        }
        
        return dp[n-1];
        
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> fir {nums.begin(),nums.begin()+n-1};
        vector<int> sec {nums.begin()+1,nums.begin()+n};
        
        int a= temp(fir);
        int b=temp(sec);
        return max(a,b);
        
    }
};
