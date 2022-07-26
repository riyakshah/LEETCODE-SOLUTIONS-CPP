class Solution {
public:
    int ans;
    void dfs(vector<vector<char>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        grid[i][j]='0';
       // visited[i][j]=1;
        if(i+1<n && grid[i+1][j]=='1'){
            dfs(grid,i+1,j);
        }
        if(i-1>=0 && grid[i-1][j]=='1'){
            dfs(grid,i-1,j);
        }
        if(j+1<m && grid[i][j+1]=='1'){
        }
        if(j-1>=0 && grid[i][j-1]=='1'){
            dfs(grid,i,j-1);
        }
        
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
       // vector<vector<bool>> visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
      
        
    }
};
