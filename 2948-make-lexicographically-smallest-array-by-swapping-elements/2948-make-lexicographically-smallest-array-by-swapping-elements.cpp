class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<int>sorted=nums;

        sort(sorted.begin(),sorted.end());

         unordered_map<int,vector<int>>group;

         unordered_map<int,int>groupid;
         unordered_map<int,int>pos;

         int id=1;

         group[id].push_back(sorted[0]);

         groupid[sorted[0]]=id;

         for(int i=1;i<n;i++){
            if(sorted[i]-sorted[i-1]>limit){
                id++;
            }
            group[id].push_back(sorted[i]);
            groupid[sorted[i]]=id;
         }

         for(int i=0;i<n;i++){
            int grp=groupid[nums[i]];

            nums[i]=group[grp][pos[grp]];
            pos[grp]++;
         }
         return nums;
    }
};