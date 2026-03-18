class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[node]=1;

        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1 && !visited[i]){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
          if(!visited[i]){
            dfs(i,isConnected,visited);
            count++;
          }
        }
        return count;
    }
};