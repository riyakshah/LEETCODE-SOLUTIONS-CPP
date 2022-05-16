class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int limit=(n-1)/2;
        for(int i=0;i<=limit;i++){
            swap(s[i],s[n-i-1]);
        }
        
        
    }
};
