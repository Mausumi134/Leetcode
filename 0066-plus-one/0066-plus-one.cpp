class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>result;
        int carry=1;
        for(int i=n-1;i>=0;i--){
           int& d=digits[i];
           d+=carry;
           carry=d==10;
           if(!carry)return digits;
           d-=10;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};