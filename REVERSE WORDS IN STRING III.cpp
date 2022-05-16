class Solution {
public:
    string reverse(string subs){
        int n=subs.length();
        int mid=(n-1)/2;
        for (int i=0;i<=mid;i++){
            swap(subs[i],subs[n-i-1]);
        }
        return subs;
    }
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        while(j<n){
            while(j<n && s[j]!=' '){
                j++;
            }
            string rer=reverse(s.substr(i,j-i));
            s.replace(i,j-i,rer);
            while(j<n && s[j]==' '){
                j++;
            }
            i=j;
        }
        return s;
        
    }
};
