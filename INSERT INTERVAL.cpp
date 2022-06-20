class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        int st;
        int end;
        int flag=0;
        while(i<n){
            if(intervals[i][1]<newInterval[0] || intervals[i][0]>newInterval[1]){
                ans.push_back(intervals[i]);
                i++;
            }
            else{
                flag=1;
                st=intervals[i][0];
                end=intervals[i][1];
                while(i<n && !(intervals[i][1]<newInterval[0] || intervals[i][0]>newInterval[1])){
                    end=max(end, intervals[i][1]);
                    i++;
                }
                st=min(newInterval[0],st);
                end=max(end, newInterval[1]);
                ans.push_back({st,end});
            }
            
        }
        if(flag==0){
            int m=ans.size();
            int r=0;
            for(int i=0;i<m;i++){
                if(ans[i][0]>newInterval[0]){
                    r=1;
                    ans.insert(ans.begin()+i, newInterval);
                    break;
                }
            }
            if(r==0){
                ans.push_back(newInterval);
            }
        }
        return ans;
        
        
    }
};
