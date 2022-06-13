class Solution {
public:
    int maxArea(vector<int>& height) {
       
        int i=0;
        int n=height.size();
        int j=n-1;
        int ans=0;
        int h=0;
        while(i<j){
            h=min(height[i],height[j]);
            ans=max(ans,h*(j-i));
            while(height[i]<=h && i<j){
                i++;
            }
            while(height[j]<=h && i<j){
                j--;
            }
        }
        return ans;
       
        
    }
};
