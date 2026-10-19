class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smallcount=0,targetcount=0;

        for(int num:nums){
            if(num<target){
                smallcount++;
            }
            else if(num==target){
                targetcount++;
            }
        }

      vector<int>result;

      int count=0;

      while(count<targetcount){
        result.push_back(smallcount);

        smallcount+=1;
        count++;
      }
        return result;

    }
};