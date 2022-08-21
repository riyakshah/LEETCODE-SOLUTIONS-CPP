class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int sum, int target,int ind,vector<int> vect){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(vect);
        }
        for(int i=ind;i<candidates.size();i++){
            vect.push_back(candidates[i]);
            helper(candidates,sum+candidates[i],target,i,vect);
            vect.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> vect;
        helper(candidates,0,target,0,vect);
        return ans;
        
    }
};
