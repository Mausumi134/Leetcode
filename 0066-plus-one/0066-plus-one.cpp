class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int carry=1;
        vector<int>ans;
        int n=arr.size();

        for(int i=n-1;i>=0;i--){
            if(arr[i]==9 && carry==1){
                ans.push_back(0);
                carry=1;
            }
            else if(arr[i]<9 && carry==1){
                ans.push_back(arr[i]+1);
                carry=0;
            }
            else if(carry==0){
                ans.push_back(arr[i]);
            }
        }

        if(carry==1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};