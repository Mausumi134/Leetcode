class Solution {
public:
    double compute(double mid,vector<vector<int>>& squares){
           double area_above=0;
           double area_below=0;
           
           for(auto &sq:squares){
            double y=sq[1];
            double l=sq[2];
            if(y>=mid){
               area_above+=l*l;
            
            }
            else if(y+l<=mid){
                area_below+=l*l;
            }
            else if(y<mid && mid<y+l){
                area_below+=l*(mid-y);
                area_above+=l*(y+l-mid);
            }
           }

           double ans=area_below-area_above;
           return ans;
    }
    double separateSquares(vector<vector<int>>& squares) {
       double left=1e18;
       double right=-1e18;
       for(auto &sq:squares){
        double y=sq[1];
        double l=sq[2];

        left=min(left,y);
        right=max(right,y+l);
       }
      
        while(right-left>1e-6){
            double mid=left+(right-left)/2;
            double diff=compute(mid,squares);
            if(diff<0){
               left=mid;
               
            }
            else{
               right=mid;
            }
        }
        return right;
    }
};