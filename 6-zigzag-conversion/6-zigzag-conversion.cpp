class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows,vector<char>(s.size(),'#'));
        
        if(numRows==1) return s;
        
        int k=1,i,j=0;
        v[0][0]=s[0];
        while(k<s.size()){
            for(i=1;i<numRows && k<s.size();i++)
            {
                v[i][j]=s[k];
                k++;
            }
           // cout<<"&&"<<i<<"&&"<<endl;
            i=i-1;
            while(k<s.size() && i>0)
            {
                v[i-1][j+1]=s[k];
                k++;
                i--;
                j++;
            }
        }
        
        
        
        string res="";
        for(i=0;i<numRows;i++)
        {
            for(j=0;j<s.size();j++)
            {
                if(v[i][j]!='#' && v[i][j]!=' ')
                    res+=v[i][j];
            }
        }
        return res;
    }
};