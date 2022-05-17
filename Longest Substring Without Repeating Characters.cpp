class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        int ans=0;
       unordered_set<char> charset;
        while(j<n){
            if(charset.find(s[j])!=charset.end()){
                while(charset.find(s[j])!=charset.end()){
                    charset.erase(s[i]);
                    i++;
                }
            }
            charset.insert(s[j]);
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};
