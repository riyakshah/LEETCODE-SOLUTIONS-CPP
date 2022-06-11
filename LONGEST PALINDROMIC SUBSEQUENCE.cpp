class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> vect(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            vect[i][i]=1;
        }
        int st=0;
        int maxLength=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                vect[i][i+1]=1;
                st=i;
                maxLength=2;
            }
            
            
        }
    
        for(int l=3;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=l+i-1;
                if(s[i]==s[j] && vect[i+1][j-1]){
                    vect[i][j]=1;
                    if(l>maxLength){
                        st=i;
                        maxLength=l;
                    }
                }
                
            }
        }
        return s.substr(st,maxLength);
    }

};
