class Solution {
public:
    int largestInteger(int num) {
       priority_queue<int>even;
       priority_queue<int>odd;

        string number=to_string(num);

        for(char c:number){
            int n=c-'0';
            if(n%2==0){
                even.push(n);
            }
            else{
                odd.push(n);
            }
        }

        string ans="";

        for(char c:number){
            int n=c-'0';
            if(n%2==0){
                if(!even.empty()){
                    ans+=(even.top()+'0');
                    even.pop();
                }
            }
            else{
                  if(!odd.empty()){
                    ans+=(odd.top()+'0');
                    odd.pop();
                }
            }
        }
        return stoi(ans);
    }
};