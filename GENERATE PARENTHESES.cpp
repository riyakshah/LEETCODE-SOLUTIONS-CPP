class Solution {
public:
    vector<string> ans;
    void helper(int n,int i,int k,int l,string st ){
        if(i==(2*n)-1){
            ans.push_back(st);
            return;
        }
        if(k<n && l>=1){
        helper(n,i+1,k+1,l,st+"(");
        }
        if(k>n-l && l>0){
            helper(n,i+1,k,l-1,st+")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string st="(";
        helper(n,0,1,n,st);
        return ans;
        
    }
};
