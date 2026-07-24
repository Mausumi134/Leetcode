class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int maxlen=0;
        unordered_map<int,int>mp;

        for(int j=0;j<n;j++){
            mp[fruits[j]]++;

            while(mp.size()>2){
                if(i<n)mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }
};