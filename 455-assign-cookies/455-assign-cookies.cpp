class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int i1=0,i2=0,n1=g.size(),n2=s.size();
        int count=0;
        while(i1<n1 && i2<n2)
        {
            if(s[i2]>=g[i1]) {count++;
            i2++;
            i1++;
            }
            else
            {
                i2++;
            }
        }
        return count;
    }
};