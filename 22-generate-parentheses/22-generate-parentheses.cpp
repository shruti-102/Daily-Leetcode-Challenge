class Solution {
public:
    vector<string> ans;
    void generater(int n,int s,string parentheses,int indx)
    {
        if(s>n && s<(-1)*n)
        {
            
            return;
        }
        if(indx==2*n){
            if(s==0)
            {
                ans.push_back(parentheses);
                return;
            }
            else
            {
                return;
            }
        }
        
        generater(n,s+1,parentheses+'(',indx+1);
        if(s>0) generater(n,s-1,parentheses+')',indx+1);
    }
    vector<string> generateParenthesis(int n) {
        generater(n,0,"",0);
        return ans;
    }
};