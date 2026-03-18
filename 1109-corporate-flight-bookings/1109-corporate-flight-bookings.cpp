class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+2,0);

        for(auto &vec:bookings){
            int start=vec[0];
            int end=vec[1];
            int seat=vec[2];
            diff[start]+=seat;
            diff[end+1]-=seat;
        }

        vector<int>res;
        int cumsum=0;
        for(int i=1;i<=n;i++){
            cumsum+=diff[i];
            res.push_back(cumsum);
        }
        return res;
    }
};