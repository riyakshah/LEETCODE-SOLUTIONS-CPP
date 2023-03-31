class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        int i=0;
        while(i<n){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty() || (s[i]==')' && st.top()!='(') || (s[i]=='}' && st.top()!='{') || (s[i]==']' && st.top()!='[')){
                    return 0;
                }
                else{
                    st.pop();
                }
            }
            i++;
        }
        if(st.empty()){
        return 1;
        }
        return 0;
        
    }
};
