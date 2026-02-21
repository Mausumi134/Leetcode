class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});

                    visited[i][j]=1;
                }
            }
        }

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto node=q.front();
            int x=node.first.first;
            int y=node.first.second;

            int step=node.second;
            ans[x][y]=step;
            q.pop();

            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];

                if(newx>=0 && newx<n && newy>=0 && newy<m && mat[newx][newy]==1 && visited[newx][newy]==0){
                    visited[newx][newy]=1;
                    q.push({{newx,newy},step+1});
                }
            }
           
        }
        return ans;
    }
};