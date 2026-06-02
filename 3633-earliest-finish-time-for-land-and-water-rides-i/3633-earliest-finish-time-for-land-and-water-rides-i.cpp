class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliest=INT_MAX;

        
       
        for (int i = 0; i < landStartTime.size(); i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterBegin = max(landFinish, waterStartTime[j]);
                int finalFinish = waterBegin + waterDuration[j];

                earliest = min(earliest, finalFinish);
            }
        }

        
        for (int i = 0; i < waterStartTime.size(); i++) {
            int waterFinish = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < landStartTime.size(); j++) {
                int landBegin = max(waterFinish, landStartTime[j]);
                int finalFinish = landBegin + landDuration[j];

                earliest = min(earliest, finalFinish);
            }
        }

        return earliest;
    }
};