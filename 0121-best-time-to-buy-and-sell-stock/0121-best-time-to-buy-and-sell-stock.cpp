class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxi=0;

        for(int p:prices){
            if(p<buy){
                buy=p;
            }
            maxi=max(maxi,p-buy);
        }
        return maxi;
    }
};