class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            set<int>st;
            int odd=0;
            int even=0;

            for(int j=i;j<n;j++){
                if(st.count(nums[j])==0 && nums[j]%2!=0){
                    odd++;
                    st.insert(nums[j]);
                }
                else if(st.count(nums[j])==0 && nums[j]%2==0){
                    
                    even++;
                    st.insert(nums[j]);
                }

                if(odd==even){
                   maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};