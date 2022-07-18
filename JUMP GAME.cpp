class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        if(n==1){
            return true;
        }
        for(int i=0;i<n && i<=reach;i++){
            int k=nums[i];
           reach=max(reach,i+k);
        }
        if(reach>=n-1){
            return true;
        }
        return false;
            
        
    }
};
