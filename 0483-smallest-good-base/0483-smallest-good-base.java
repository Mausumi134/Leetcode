class Solution {
    public String smallestGoodBase(String n) {
        long num=Long.parseLong(n);

        for(int i=63;i>=2;i--){
            long l=2,h=num-1;

            while(l<=h){
                long m=l+(h-l)/2;

                long sum=1,x=1;
                boolean overflow=false;
                for(int j=1;j<i;j++){
                    if(x>num/m){
                       overflow=true;
                       break;
                    }
                    x*=m;
                    sum+=x;

                    if(sum>num)break;
                }
                if(sum==num)return String.valueOf(m);
                else if(overflow || sum>num)h=m-1;
                else l=m+1;
            }
        }
        return String.valueOf(num-1);
    }
}