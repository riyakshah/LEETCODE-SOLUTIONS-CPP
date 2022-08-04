class Solution {
public:
    static bool sortcol(const vector<int>& v1,const vector<int>& v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),sortcol);
        int mini=intervals[0][0];
        int maxi=intervals[0][1];
        int i=1;
        bool c=0;
       while(i<n){
           c=0;
            while(i<n && intervals[i][0]>=mini && intervals[i][0]<=maxi){
                mini=min(mini,intervals[i][0]);
                maxi=max(maxi,intervals[i][1]);
                i++;
                //c=1;
            }
           
           ans.push_back({mini,maxi});
           if(i<n){
               c=1;
               mini=intervals[i][0];
               maxi=intervals[i][1];
               i++;
           }
           
               
            
        }
        if(c==1){
            ans.push_back({mini,maxi});
        }
        return ans;
        
    }
};
