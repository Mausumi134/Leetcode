class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;


        int best=0,ans=0;
        for(auto q:events){
            int start=q[0];
            int end=q[1];
            int val=q[2];
            

            while(!pq.empty() && pq.top().first<start){
                best=max(pq.top().second,best);
                pq.pop();
            }

            ans=max(ans,best+val);
            pq.push({end,val});

        }


      return ans;
    }
};