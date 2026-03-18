class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int x,int y,vector<vector<int>>& visited,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        visited[x][y]=1;

        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];

            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1 && !visited[newx][newy]){
                dfs(newx,newy,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(!visited[0][i] && grid[0][i]==1){
                dfs(0,i,visited,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(!visited[n-1][i] && grid[n-1][i]==1){
                dfs(n-1,i,visited,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i,0,visited,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,visited,grid);
            }
        }

      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(!visited[i][j] && grid[i][j]==1){
            count++;
           }
        }
      }
      return count;
    }
};