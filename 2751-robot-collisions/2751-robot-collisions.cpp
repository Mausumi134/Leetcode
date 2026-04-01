class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<tuple<int,int,char,int>> robots;

        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        vector<int> alive(n, 1); 
        stack<int> st; 

        for(int i = 0; i < n; i++) {
            char dir = get<2>(robots[i]);

            if(dir == 'R') {
                st.push(i);
            } else {
           
                while(!st.empty()) {
                    int j = st.top();

                    if(get<1>(robots[j]) < get<1>(robots[i])) {
                       
                        alive[j] = 0;
                        st.pop();
                        get<1>(robots[i])--; 
                    }
                    else if(get<1>(robots[j]) > get<1>(robots[i])) {
                        
                        alive[i] = 0;
                        get<1>(robots[j])--;
                        break;
                    }
                    else {
                        
                        alive[i] = 0;
                        alive[j] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> ans(n);

     
        for(int i = 0; i < n; i++) {
            if(alive[i]) {
                int originalIndex = get<3>(robots[i]);
                ans[originalIndex] = get<1>(robots[i]);
            }
        }

       
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(ans[i] != 0) {
                res.push_back(ans[i]);
            }
        }

        return res;
    }
};