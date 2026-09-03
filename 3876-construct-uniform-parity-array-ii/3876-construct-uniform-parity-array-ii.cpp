class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int minodd=INT_MAX;
       int countodd=0;

       for(int num:nums1){
        minodd=min(minodd,num);
        if(num%2==1)countodd++;
       }
       return minodd%2 || countodd==0;
    }
};