class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        pq.push({1, start});
        
        vector<double>dist(n, 0);
        dist[start] = 1;
        
        while(!pq.empty()){
            
            double distance = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(int i = 0 ; i < graph[node].size(); i++){
                // cout << distance<< " " << graph[node][i].second<< endl;
                if(dist[graph[node][i].first] < distance * graph[node][i].second){
                    dist[graph[node][i].first] = distance * graph[node][i].second;
                    pq.push({dist[graph[node][i].first], graph[node][i].first});
                }
            }
            
            
        }
        
        return dist[end];
        
        
    }
};
