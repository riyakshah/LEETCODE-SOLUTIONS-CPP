class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int n=grumpy.size();
        int temp=0;
        for(int i=0;i<minutes;i++){
            if(!grumpy[i]){
                ans=ans+customers[i];
            }
            else{
                temp=temp+customers[i];
            }
            
        }
        int maxi=temp;
        for(int i=minutes;i<n;i++){
            if(!grumpy[i]){
                ans=ans+customers[i];
                if(grumpy[i-minutes]){
                    temp=temp-customers[i-minutes];
                }
            }
            else{
            if(grumpy[i-minutes]){
                temp=temp-customers[i-minutes]+customers[i];
            }
            else{
                temp=temp+customers[i];
            }            
        }
            maxi=max(maxi,temp);
        }
        ans=ans+maxi;
        return ans;
            
        
    }
};
