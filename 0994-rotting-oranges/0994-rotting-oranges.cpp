class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int maxtime=0;

        while(!q.empty()){
            pair<pair<int,int>,int>node=q.front();
            q.pop();
            int x=node.first.first;
            int y=node.first.second;
            int time=node.second;
            maxtime=max(maxtime,time);

            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];

                if(newx>=0 && newx<n && newy>=0 && newy<m && !visited[newx][newy] && grid[newx][newy]==1){
                    grid[newx][newy]=2;
                    visited[newx][newy]=1;

                    q.push({{newx,newy},time+1});
                }
            }


        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
         }
         return maxtime;
    }
};