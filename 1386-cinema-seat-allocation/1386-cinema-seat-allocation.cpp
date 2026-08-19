class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rows;

        for(auto seat:reservedSeats) {
            int row=seat[0];
            int col=seat[1];
            rows[row]|=(1<<col);
        }

        int count=2*n;

        for(auto [row,mask]:rows) {
            bool left=(mask&(1<<2))==0 &&
                      (mask&(1<<3))==0 &&
                      (mask&(1<<4))==0 &&
                      (mask&(1<<5))==0;

            bool right=(mask&(1<<6))==0 &&
                       (mask&(1<<7))==0 &&
                       (mask&(1<<8))==0 &&
                       (mask&(1<<9))==0;

            if(left&&right) {
            }
            else if(left||right) {
                count--;
            }
            else {
                bool middle=(mask&(1<<4))==0 &&
                            (mask&(1<<5))==0 &&
                            (mask&(1<<6))==0 &&
                            (mask&(1<<7))==0;

                if(middle)
                    count--;
                else
                    count-=2;
            }
        }

        return count;
    }
};