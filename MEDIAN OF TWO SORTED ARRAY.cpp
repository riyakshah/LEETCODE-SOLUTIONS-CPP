class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int r=m*2;
        while(l<=r){
            int mid2=(l+r)/2;
            int mid1=n+m-mid2;
            double L1,L2,R1,R2;
            if(mid1==0){
                L1=INT_MIN;
            }
            else{
                L1=nums1[(mid1-1)/2];
            }
            
            if(mid2==0){
                L2=INT_MIN;
            }
            else{
                L2=nums2[(mid2-1)/2];
            } 
            
            if(mid1==n*2){
                R1=INT_MAX;
            }
            else{
                R1=nums1[(mid1)/2];
            }
            
            if(mid2==m*2){
                R2=INT_MAX;
            }
            else{
                R2=nums2[(mid2)/2];
            }
            if(L1>R2){
                l=mid2+1;
            }
            else if(L2>R1){
                r=mid2-1;
            }
            else{
            return (max(L1,L2)+min(R1,R2))/2;
            }
            
            
        }
        return -1;
        
    }
};
