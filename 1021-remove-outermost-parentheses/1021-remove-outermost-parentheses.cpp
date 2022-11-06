class Solution {
public:
    string removeOuterParentheses(string s) {
        //stack<char> st;
        string res;
        int score=0;
        for(auto x:s)
        {
            if(x=='(')
            {
                if(score!=0)
                {
                    res.push_back(x);
                }    
                //st.push(x);
                score+=1;
            }
            
            
            else
            {
                //st.pop();
                score-=1;
                if(score!=0)
                    res.push_back(x);
            }
        }
        return res;
    }
};