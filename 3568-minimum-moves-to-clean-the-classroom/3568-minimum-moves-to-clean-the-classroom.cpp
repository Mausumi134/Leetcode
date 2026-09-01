class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();

        int startr=0,startc=0;

        int totallitter=0;

        vector<vector<int>>litterindex(m,vector<int>(n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    startr=i;
                    startc=j;
                }

                if(classroom[i][j]=='L'){
                    litterindex[i][j]=totallitter;
                    totallitter++;
                }
            }
        }

        int alllittermask=(1<<totallitter)-1;


        queue<tuple<int,int,int,int>> q;
        q.push({startr, startc, energy, 0});

        vector<vector<vector<vector<bool>>>>visited(m,
vector<vector<vector<bool>>>(n,vector<vector<bool>>(energy + 1,
vector<bool>(1 << totallitter, false))));

     visited[startr][startc][energy][0]=true;

     int moves=0;

     int dr[]={-1,1,0,0};
     int dc[]={0,0,-1,1};


     while(!q.empty()){
        int size=q.size();
        while(size--){
            auto[r,c,e,mask]=q.front();
            q.pop();

            if(mask==alllittermask)return moves;

            if(e==0)continue;

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                 if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int idx = litterindex[nr][nc];
                        nmask |= (1 << idx);
                    }

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
           
     }
     return -1;
    }
};