class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        int l1=strs[0].size();
        int l2=strs[1].size();
        string prefix="";
        int l=min(l1,l2);
        
        for(int i=0;i<l;i++)
        {
            if(strs[0][i]==strs[1][i]) prefix+=strs[1][i];
            else break;
        }
        //cout<<prefix;
        for(int i=2;i<strs.size();i++)
        {
            for(int j=0;j<prefix.size();j++)
            {
                if(strs[i][j]!=prefix[j])
                {
                    prefix=strs[i].substr(0,j);
                    //cout<<"%"<<prefix<<" ";
                    break;
                }
                
            }
        }
        return prefix;
    }
};