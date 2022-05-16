class Solution {
public:
    int bsearch(int n, int l, int r){
        int mid=l+((r-l)/2);
        
        if(l>r){
            return l;
        }
        else if(isBadVersion(mid)){
            return bsearch(n,l,mid-1);
        }
        return bsearch(n,mid+1,r);
             
    }
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        return bsearch(n,l,r);        
    }
};
