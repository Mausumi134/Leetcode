class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(int i,int j,int n,int m,long long& sum,vector<vector<int>>& grid,vector<vector<int>>& visited){
       visited[i][j]=1;
       sum+=grid[i][j];
       for(int k=0;k<4;k++){
           int x=i+dx[k];
           int y=j+dy[k];

           if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>0 && visited[x][y]!=1){
               dfs(x,y,n,m,sum,grid,visited);
           }
       }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        long long sum=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]>0 && !visited[i][j]){
                  sum=0;
                   dfs(i,j,n,m,sum,grid,visited);
                   if(sum%k==0)count++;
            }
        }
       }
    
      return count;

    }
};