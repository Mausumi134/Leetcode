class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        int mini=INT_MAX;

        vector<int>mn_till(n,0);

        for(int i=n-1;i>=0;i--){
            mini=min(mini,arr[i]);
            mn_till[i]=mini;
        }

        int maxi=arr[0];

        for(int i=1;i<n;i++){
            if(maxi<=mn_till[i]){
                count++;
                maxi=arr[i];
            }
            else{
                maxi=max(maxi,arr[i]);
            }
        }
        return count+1;
    }
};