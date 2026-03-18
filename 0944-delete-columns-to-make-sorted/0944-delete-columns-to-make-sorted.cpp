class Solution {
public:
    bool isUnsorted(vector<string>& strs,int j){
        for(int i=1;i<strs.size();i++){
            if(strs[i][j]<strs[i-1][j]){
                return true;
            }
        }
        return false;
    }
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        for(int i=0;i<strs[0].size();i++){
            count+=isUnsorted(strs,i);
        }
        return count;
    }
};