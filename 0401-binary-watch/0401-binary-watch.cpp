class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;

        for(int i=0;i<=11;i++){
            for(int j=0;j<60;j++){
                if(__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
                    string hh=to_string(i);
                    string mm=(j<10 ? "0":"")+to_string(j);
                    ans.push_back(hh+":"+mm);
                }
            }
        }
        return ans;
    }
};