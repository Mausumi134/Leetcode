class Solution {
public:
    int reverseNum(int n){
       int rev=0;
       while(n!=0){
        int rem=n%10;
        rev=rev*10+rem;
        n/=10;
       }
       return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
         int dis=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int revn=reverseNum(nums[i]);
            if(mp.find(nums[i])!=mp.end()){
                dis=min(dis,abs(i-mp[nums[i]]));
            }
            mp[revn]=i;
        }
        return dis!=INT_MAX? dis:-1;
    }
};