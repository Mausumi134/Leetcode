class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int>minY,minX,maxY,maxX;

        const int INF=1e9;

        for(auto &b:buildings){
            int x=b[0],y=b[1];
            if(!minY.count(x))minY[x]=INF;
            if (!maxY.count(x)) maxY[x] =-INF;
            if (!minX.count(y)) minX[y] =INF;
            if (!maxX.count(y)) maxX[y] =-INF;
        minY[x] = min(minY[x], y);
        maxY[x] = max(maxY[x], y);
        minX[y] = min(minX[y], x);
        maxX[y] = max(maxX[y], x);

        }
        int ans=0;
    for (auto &b:buildings) {
        int x=b[0], y=b[1];
        if(minY[x] < y && y < maxY[x] && minX[y] < x && x < maxX[y]) ans++;
    }
    return ans;
    }
};