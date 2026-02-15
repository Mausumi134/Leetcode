class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();

        int i=n-1,j=m-1;
        string res="";
        char carry='0';

        while(i>=0 || j>=0){
            char x = (i>=0)? a[i] : '0';
            char y = (j>=0)? b[j] : '0';

            if(x=='1' && y=='1'){
                res += (carry=='1') ? '1' : '0';
                carry='1';
            }
            else if(x=='0' && y=='0'){
                res += carry;
                carry='0';
            }
            else{
                if(carry=='1'){
                    res+='0';
                    carry='1';
                } else {
                    res+='1';
                    carry='0';
                }
            }
            i--;
            j--;
        }

        if(carry=='1') res+='1';

        reverse(res.begin(),res.end());
        return res;
    }
};
