class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit=max(*max_element(forbidden.begin(),forbidden.end()),x)+a+b;

        queue<pair<int,bool>>q;
        set<pair<int,bool>>visited;

        for(int num:forbidden){
            visited.insert({num,false});
            visited.insert({num,true});
        }
        q.push({0,false});
        visited.insert({0,false});
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                int pos=node.first;
                bool backused=node.second;
                if(pos==x)return steps;
                int forward=pos+a;
                if(forward<=limit && !visited.count({forward,false})){
                    visited.insert({forward,false});
                    q.push({forward,false});
                }

                if(!backused){
                    int backward=pos-b;
                    if(backward>=0 && !visited.count({backward,true})){
                        visited.insert({backward,true});
                        q.push({backward,true});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};