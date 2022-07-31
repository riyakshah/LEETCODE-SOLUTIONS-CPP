class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<vector<int>> lr(n,vector<int>(2,0));
        lr[0]={0,0};
        lr[n-1]={0,0};
        int ans=0;
    
        int maxi=height[0];
        int maxi2=height[n-1];
        for(int i=1;i<n;i++){
            if(height[i]>maxi){
                maxi=height[i];
            }
            lr[i][0]=maxi;
        }
        for(int i=n-2;i>=0;i--){
            if(height[i]>maxi2){
                maxi2=height[i];
            }
            lr[i][1]=maxi2;
        }
        for(int i=0;i<n;i++){
            int k=min(lr[i][0],lr[i][1]);
            if(k>height[i]){
            ans=ans+(k-height[i]);
            }
            
        }
        return ans;

        
    }
};
