class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevval=-1;
        while(n>0){
            int bit=n%2;
            if(prevval==bit){
                return false;
            }else{
                prevval=bit;
            }
            n/=2;
        }
        return true;
    }
};