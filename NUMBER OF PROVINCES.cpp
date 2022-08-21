class Solution {
public:
    void dfs(vector<vector<int>>& graph,int i,int j){
        graph[i][j]=0;
        graph[j][i]=0;
        
        int n=graph.size();
        for(int k=0;k<n;k++){
            if(graph[i][k]){
                dfs(graph,i,k);
            }
        }
        for(int k=0;k<n;k++){
            if(graph[j][k]){
                dfs(graph,j,k);
            }
        }
        
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m= isConnected[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    ans++;
                    dfs(isConnected,i,j);
                }
            }
        }
        return ans;
        
    }
};
