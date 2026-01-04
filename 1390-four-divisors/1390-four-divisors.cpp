class Solution {
public:
     
    int sumFourDivisors(vector<int>& nums) {
        
        int sum=0;
        for(int num:nums){
            int count=0;
            int currsum=0;
            
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    if(i*i==num){
                    currsum+=i;
                    count++;
                    }
                    else{
                        count+=2;
                        currsum+=(i+num/i);
                    }
                }
                if(count>4)break;
            }
            if(count==4){
               sum+=currsum;
            }
        }
        return sum;
    }
};