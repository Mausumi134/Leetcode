class Solution {
public:
    int bestClosingTime(string customers) {
        int minpenalty=0,curr=0;
        int n=customers.size();
        int earliest=0;

        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                 curr--;
            }
            else{
                curr++;
            }

            if(curr<minpenalty){
                earliest=i+1;
                minpenalty=curr;
            }
        }
        return earliest;
    }
};