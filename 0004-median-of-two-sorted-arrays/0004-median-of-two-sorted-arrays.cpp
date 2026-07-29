class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int m=nums1.size();
        int n=nums2.size();
        int total=m+n;

        int low=0,high=m;
        
        while(low<=high){
        int cut1=low+(high-low)/2;
        int cut2=((m+n+1)/2)-cut1;


        int L1=(cut1==0)?INT_MIN:nums1[cut1-1];
        int R1=(cut1==m)?INT_MAX:nums1[cut1];
        int L2=(cut2==0)?INT_MIN:nums2[cut2-1];
        int R2=(cut2==n)?INT_MAX:nums2[cut2];
        

        if(L1<=R2 && L2<=R1){
            if(total%2!=0){
                return max(L1,L2);
            }
            else{
               return (max(L1,L2)+min(R1,R2))/2.0;
            }
        }
        else if(L1>R2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
        }
        return 0.0;
    }
};