class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size())
        {
            if(st.empty()) st.push(s[i]);
            else if(s[i]==')' && st.top()=='(') st.pop();
            else if(s[i]=='}' && st.top()=='{') st.pop();
            else if(s[i]==']' && st.top()=='[') st.pop();
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            
            else return false;
            i++;
        }
        if(st.size()>0) return false;
        return true;
    }
};