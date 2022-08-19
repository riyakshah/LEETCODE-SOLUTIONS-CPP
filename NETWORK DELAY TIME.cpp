class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> vp;
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        vector<int> dist(n+1, INT_MAX);
        vp.push(make_pair(0,k));
        dist[k]=0;
        //int d;
        while(!vp.empty()){
            auto r= vp.top();
            vp.pop();
            int d= r.first;
            int node= r.second;
            for(int i=0;i<graph[node].size();i++){
                if(dist[graph[node][i].first]>d+graph[node][i].second){
                    dist[graph[node][i].first]=d+graph[node][i].second;
                    vp.push(make_pair(dist[graph[node][i].first],graph[node][i].first));
                
            }
                                                            
        }
       }
                                                      
        int ans=INT_MIN;
                                                      
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            if(dist[i]>ans){
                ans=dist[i];
            }
        }
        return ans;
      
        
    }
};
