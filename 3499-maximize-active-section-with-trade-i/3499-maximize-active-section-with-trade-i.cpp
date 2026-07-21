class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t=("1")+s+("1");
        int intialone=0;

        for(char c:s){
            if(c=='1'){
                intialone++;
            }
        }
        vector<pair<char,int>>block;

        char curr=t[0];
        int count=1;

        for(int i=1;i<t.size();i++){
            if(t[i]==curr){
                count++;
            }
            else{
                block.push_back({curr,count});
                curr=t[i];
                count=1;
            }
        }
        block.push_back({curr,count});
        int maxgain=0;
        for(int i=1;i<block.size()-1;i++){
            if(block[i].first=='1' && block[i-1].first=='0' && block[i+1].first=='0'){
               int gain=block[i-1].second+block[i+1].second;
               maxgain=max(gain,maxgain);
            }
        }

        return maxgain+intialone;

    }
};