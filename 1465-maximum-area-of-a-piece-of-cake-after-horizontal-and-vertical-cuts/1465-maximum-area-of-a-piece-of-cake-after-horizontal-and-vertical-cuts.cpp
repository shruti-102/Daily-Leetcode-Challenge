class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int M = 1000000007;
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        
        int maxdiffrow=0,maxdiffcol=0;
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            maxdiffrow=max(maxdiffrow,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        for(int i=1;i<verticalCuts.size();i++)
        {
            maxdiffcol=max(maxdiffcol,verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return ((maxdiffcol%M)*(maxdiffrow%M))%M;
    }
};