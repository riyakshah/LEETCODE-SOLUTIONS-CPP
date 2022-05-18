class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int sum=0;
        int j=0;
        int ans=INT_MAX;
        while(i<n && j<n){
            int c=0;
           // sum=sum+nums[j];
            if(sum<target){
                sum=sum+nums[j];
                j++;
            }
            if(sum>=target || j==n){
                //ans=min(ans,j-i);
                while(sum>=target && i<n){
                    sum=sum-nums[i];
                    i++;
                    c++;
                
                }
                if(c!=0){
                ans=min(ans,j-i+1);
                }
                
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
        
    }
};
