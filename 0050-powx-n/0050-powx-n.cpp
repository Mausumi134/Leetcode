class Solution {
public:
   double pow(double x,long n){
    if(n==0)return 1;
    if(n==1)return x;
    if(n<0)return pow(1/x,-n);
    if(n%2==0)return pow(x*x,n/2);
    else return x*pow(x*x,(n-1)/2);
   }
    double myPow(double x, int n) {
        return pow(x,(long)n);
    }
};