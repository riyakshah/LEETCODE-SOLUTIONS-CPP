class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> ans;
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && asteroids[i]<0 && st.top()>0){
                int temp=st.top();
                if(temp>abs(asteroids[i])){
                    continue;
                }
                else{
                    while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top()){
                        st.pop();
                    }
                    if(st.empty() || st.top()<0){
                        st.push(asteroids[i]);
                    }
                    if(!st.empty() && st.top()>0 && abs(asteroids[i])==st.top()){
                        st.pop();
                    }
                }
            }
            
            else{
                st.push(asteroids[i]);
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
