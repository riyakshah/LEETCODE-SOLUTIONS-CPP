class Solution {
public:
    vector<vector<int>> ans;
  
    void recur(vector<int> vect,int i,int n,int k){
        if(vect.size()>k){
          return;
        }
        if(vect.size()==k){
            ans.push_back(vect);
            return;
        }
        //vect.push_back(i);
        for(int j=i;j<=n;j++){
        vect.push_back(j);
        recur(vect,j+1,n,k);
        vect.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vect;
        recur(vect,1,n,k);
        return ans;

    
        
    }
};
