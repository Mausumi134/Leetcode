// class Solution {
// public:
//     long long maxSumTrionic(vector<int>& arr) {

//         int n=arr.size();

        
//         vector<long long>pref(n+1,0);

//         for(int i=0;i<n;i++){
//             pref[i+1]=pref[i]+arr[i];
//         }

//         long long ans=LLONG_MIN;

//         for(int start=0;start<n-2; start++){

//             int i=start;

          
//             while(i<n-1 && arr[i]<arr[i+1]) i++;
//             int p=i;
//             if(p==start) continue;

//             while(i<n-1 && arr[i]>arr[i+1]) i++;
//             int q=i;
//             if(q==p) continue;

        
//             int k=q;
//             while(k<n-1 && arr[k]<arr[k+1]){
//                 k++;

//                 long long sum=pref[k+1]-pref[start];
//                 ans = max(ans,sum);
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<long long>p(n+1,0);
        vector<long long>s(n);
        long long last=1e16;
        for(int i=0;i<n;i++){
            p[i+1]=p[i]+nums[i];
        }
        s[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1])s[i]=max((long long)nums[i],nums[i]+s[i+1]);
            else s[i]=nums[i];
        }
        long long ans=-last;
        long long currP=nums[0]; 
        long long maxPV=-last;   
        for(int i=1;i<n;++i){ 
            long long prevP=currP;
            if(nums[i]>nums[i-1])currP=max(currP+nums[i],(long long)nums[i-1]+nums[i]);
            else currP=nums[i]; 
            if(nums[i]<nums[i-1]){ 
                if(i-1>0 && nums[i-1]>nums[i-2]){ 
                    maxPV=max(maxPV,prevP-p[i]);
                } 
                if(i<n-1 && nums[i]<nums[i+1]){ 
                    if(maxPV>-last/2){
                         ans=max(ans,maxPV+nums[i]+s[i+1]+p[i]);
                    }
                }   
            }else{ 
                maxPV=-last;
            }
        }
        return ans;
    }
};