class Solution {
public:
    
    int bsearch(vector<int>& nums, int target, int l, int r){
        
        if(l>r){
            return l;
        }
        int mid=l+((r-l)/2);
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return bsearch(nums,target,l,mid-1);
        }
        return bsearch(nums,target,mid+1,r);
        
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        return bsearch(nums,target,l,r);
        
        
        
        
        
    }
};
