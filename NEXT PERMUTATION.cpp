class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return;
        }
        bool c=0;
        int mini=INT_MAX;
        int ind=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    //c=1;
                    //swap(nums[i],nums[j]);
                    if(nums[j]<mini){
                        mini=nums[j];
                        ind=j;
                    }
                   // break;
                }
            }
            if(mini!=INT_MAX){
            c=1;
            swap(nums[i],nums[ind]);
            sort(nums.begin()+i+1,nums.end());
            break;
            }
            }
        
        if(!c){
            sort(nums.begin(),nums.end());
        }
        
    }
};
