class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(int x,int y,int n,int m,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];

            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1' && !visited[newx][newy]){
                dfs(newx,newy,n,m,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(i,j,n,m,grid,visited);
                }
            }
        }
        return count;
    }
};